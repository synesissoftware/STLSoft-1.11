#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}

RunMake=1


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    -M|--no-make)

      RunMake=0
      ;;
    --help)

      cat << EOF
STLSoft is a suite of libraries that provide STL extensions and facades over operating-system and technology-specific APIs
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
Runs all (matching) scratch-test programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -M
    --no-make
        does not execute CMake and make before running tests


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

status=0

if [ $RunMake -ne 0 ]; then

  echo "Executing make and then running all test programs"

  mkdir -p $CMakeDir || exit 1

  cd $CMakeDir

  make
  status=$?
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"
  else

    echo "Running all test programs"
  fi

  cd $CMakeDir
fi

if [ $status -eq 0 ]; then

  for f in $(find $CMakeDir -type f '(' -name 'test_scratch*' -o -name 'test.scratch.*' ')' -exec test -x {} \; -print)
  do

    echo
    echo "executing $f:"

    if $f; then

      :
    else

      status=$?
    fi
  done
fi

cd ->/dev/null

exit $status


# ############################## end of file ############################# #

