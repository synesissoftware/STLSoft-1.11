#! /usr/bin/env ruby

# ######################################################################## #
# File:     dev/bin/generate_cmakelists.rb
#
# Purpose:  Creates or regenerates CMakeLists.txt files in a manner
#           compatible with Synesis Information Systems' libraries.
#
# Created:  9th January 2025
# Updated:  10th January 2025
#
# Author:   Matthew Wilson
#
# Copyright (c) Matthew Wilson, Synesis Information Systems
# All rights reserved
#
# ######################################################################## #


# ######################################################################## #
# requires

require 'highline'
require 'libclimate'
require 'recls'


# ######################################################################## #
# includes


# ######################################################################## #
# constants

PROGRAM_VER_MAJOR = 0
PROGRAM_VER_MINOR = 1
PROGRAM_VER_PATCH = 2

FILES_TO_IGNORE = [
  'implicit_link.c',
  'implicit_link.cpp',
  /\.dsp$/,
  /\.vcproj$/,
  /\.vcxproj$/,
  /\.vcxproj.filters$/,
]


# ######################################################################## #
# functions

def get_program_source_entry entries, **options

  entries.find { |fe| fe.file? && [ '.c', '.cpp' ].include?(fe.extension) && [ 'entry', 'main' ].include?(fe.stem) }
end

def strip_excludes contents, ignore_list, **options

  def match_item fe, ignore_list

    ignore_list.each do |ignore|

      case ignore
      when ::Regexp

        return true if ignore =~ fe.basename
      when ::String

        return true if ignore == fe.basename
      else
      end
    end

    false
  end

  contents.reject { |fe| match_item fe, ignore_list }
end


# ######################################################################## #
# command-line handling

options = {}
climate = LibCLImate::Climate.new do |cl|

  cl.add_flag('--verbose', alias: '-v', help: 'operate verbosely') { options[:verbose] = true }

  cl.info_lines = [
    'STLSoft Development Tools',
    'Copyright Synesis Software Pty Ltd (c) 1999-2019, Synesis Information Systems Pty Ltd (c) 2019-2025',
    :version,
    "Creates or regenerates CMakeLists.txt files in a manner compatible with Synesis Information Systems' libraries",
    nil,
  ]
  cl.value_names = [ 'directory' ]
  cl.constrain_values = 1..;
  cl.usage_values = '<directory-1> [ ... <directory-N> ]'
end

r = climate.run ARGV

directories = r.values

directories.all? { |directory| Recls.directory? directory } or climate.abort "one or more of given arguments is not a directory"


# ######################################################################## #
# main()

num_directories_processed     = 0
num_custom_directories_found  = 0
num_missing_makelists_created = 0
num_stock_makelists_replaced  = 0


directories.each do |directory|

  # Search each top-level directory for its subdirectories

  $stdout.puts "processing in #{HighLine.color(directory, :blue, :bold)} ..." if options[:verbose]

  subdirectories = Recls.rsearch(directory, nil, Recls::DIRECTORIES).to_a#.map { |fe| fe.path }

  # now process each of these according to whether it is leaf or not

  subdirectories.each do |subdirectory|

    $stdout.print "\tprocessing #{HighLine.color(subdirectory.search_relative_path, :blue, :bold)} - " if options[:verbose]

    num_directories_processed += 1

    cml_path = Recls.combine_paths(subdirectory, 'CMakeLists.txt')
    cml = Recls.stat(cml_path)

    regenerate_cml = false

    if cml

      lines = IO.readlines cml_path

      if lines.empty?

        num_missing_makelists_created += 1

        regenerate_cml = true
      elsif lines[0].strip == '# SIS:AUTO_GENERATED: Remove this line if you edit the file, otherwise it will be overwritten'

        regenerate_cml = true

        num_stock_makelists_replaced += 1
      else

        $stdout.puts HighLine.color("ignoring custom 'CMakeLists.txt'", :cyan, :bold) if options[:verbose]
      end
    else

      num_missing_makelists_created += 1

      regenerate_cml = true
    end

    unless regenerate_cml

      num_custom_directories_found += 1
    end

    if regenerate_cml

      contents = Recls.search(subdirectory, nil, Recls::FILES | Recls::DIRECTORIES).to_a

      contents = strip_excludes contents, FILES_TO_IGNORE, **options

      fe_prg = get_program_source_entry contents

      is_leaf = true
      is_leaf = is_leaf && !contents.any? { |fe| fe.directory? }
      is_leaf = is_leaf && fe_prg

      if is_leaf

        $stdout.puts HighLine.color("generating LEAF", :magenta, :bold) if options[:verbose]

        File.open(cml_path, 'w') do |f|

          f << <<-END_of_
# SIS:AUTO_GENERATED: Remove this line if you edit the file, otherwise it will be overwritten
#{fe_prg.stem == 'entry' ? 'define_automated_test_program' : 'define_example_program'}(#{subdirectory.basename} #{fe_prg.basename})

END_of_
        end
      else

        $stdout.puts HighLine.color("generating non-LEAF", :magenta, :bold) if options[:verbose]

        File.open(cml_path, 'w') do |f|

          f << <<-END_of_
# SIS:AUTO_GENERATED: Remove this line if you edit the file, otherwise it will be overwritten
END_of_

          subdirectory_names = contents.map { |fe| fe.basename }.to_a.sort

          subdirectory_names.each do |subdir_name|

            next if subdir_name == 'CMakeLists.txt'

            f << "add_subdirectory(#{subdir_name})" << "\n"
          end

          f << "\n"
        end
      end
    end
  end
end

$stdout.puts "#{num_directories_processed} directories processed, in which there were #{num_custom_directories_found} custom configuration(s), #{num_missing_makelists_created} missing configuration(s), #{num_stock_makelists_replaced} stock configuration(s)"


# ############################## end of file ############################# #

