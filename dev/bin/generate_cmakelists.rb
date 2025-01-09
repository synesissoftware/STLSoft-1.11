#! /usr/bin/env ruby

# ######################################################################## #
# File:     dev/bin/generate_cmakelists.rb
#
# Purpose:  Creates or regenerates CMakeLists.txt files in a manner
#           compatible with Synesis Information Systems' libraries.
#
# Created:  9th January 2025
# Updated:  9th January 2025
#
# Author:   Matthew Wilson
#
# Copyright (c) Matthew Wilson, Synesis Information Systems
# All rights reserved
#
# ######################################################################## #


# ######################################################################## #
# requires

require 'libclimate'
require 'recls'


# ######################################################################## #
# includes


# ######################################################################## #
# constants


# ######################################################################## #
# functions

def get_program_source_entry entries

  entries.find { |fe| fe.file? && [ '.c', '.cpp' ].include?(fe.extension) && [ 'entry', 'main' ].include?(fe.stem) }
end


# ######################################################################## #
# command-line handling

options = {}
climate = LibCLImate::Climate.new do |cl|

  cl.constrain_values = 1..;
  cl.usage_values = '<directory-1> [ ... <directory-N> ]'
end

r = climate.run ARGV

directories = r.values

directories.all? { |directory| Recls.directory? directory } or climate.abort "one or more of given arguments is not a directory"


# ######################################################################## #
# main()

directories.each do |directory|

  # Search each top-level directory for its subdirectories

  $stderr.puts "processing in #{directory} ..."

  subdirectories = Recls.rsearch(directory, nil, Recls::DIRECTORIES).to_a#.map { |fe| fe.path }

  # now process each of these according to whether it is leaf or not

  subdirectories.each do |subdirectory|

    $stderr.puts "\tprocessing #{subdirectory}:"

    cml_path = Recls.combine_paths(subdirectory, 'CMakeLists.txt')
    cml = Recls.stat(cml_path)

    regenerate_cml = false

    if cml

      lines = IO.readlines cml_path

      if lines.empty?

        regenerate_cml = true
      elsif lines[0].strip == '# SIS:AUTO_GENERATED: Remove this line if you edit the file, otherwise it will be overwritten'

      else

        $stderr.puts "\t\t - found custom 'CMakeLists.txt'"
      end
    else

      regenerate_cml = true
    end

    if regenerate_cml

      contents = Recls.search(subdirectory, nil, Recls::FILES | Recls::DIRECTORIES).to_a

      fe_prg = get_program_source_entry contents

      is_leaf = true
      is_leaf = is_leaf && !contents.any? { |fe| fe.directory? }
      is_leaf = is_leaf && fe_prg

      if is_leaf

        File.open(cml_path, 'w') do |f|

          f << <<-END_of_
# SIS:AUTO_GENERATED: Remove this line if you edit the file, otherwise it will be overwritten
#{fe_prg.stem == 'entry' ? 'define_automated_test_program' : 'define_example_program'}(#{subdirectory.basename} #{fe_prg.basename})
END_of_
        end
      else

      end
    end
  end
end


# ############################## end of file ############################# #


