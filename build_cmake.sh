#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build

IgnoreRemainingFlagsAndOptions=0
Targets=()


# ##########################################################
# functions

function join_by { local IFS="$1"; shift; echo "$*"; }


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

    if [ $IgnoreRemainingFlagsAndOptions -ne 0 ]; then

        Targets+=($1)

        shift

        continue
    else

        if [ ! ${1:0:1} = '-' ]; then

            Targets+=($1)

            shift

            continue
        fi
    fi

    case $1 in
        --)

            IgnoreRemainingFlagsAndOptions=1
            ;;
        --help)
            cat << EOF
STLSoft is a suite of libraries that provide STL extensions and facades over operating-system and technology-specific APIs
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
Executes CMake-generated artefacts to (re)build project

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:


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

if [ ! -d "$CMakePath" ]; then

    >&2 echo "$ScriptPath: CMake build directory '$CMakePath' not found so nothing to do; use script 'prepare_cmake.sh' if you wish to prepare CMake artefacts"

    exit 1
else

    cd $CMakePath

    if [ ! -f "$CMakePath/Makefile" ]; then

        >&2 echo "$ScriptPath: CMake build directory '$CMakePath' does not contain expected file 'Makefile', so a clean cannot be performed. It is recommended that you remove all CMake artefacts using script 'remove_cmake_artefacts.sh' followed by regeneration via 'prepare_cmake.sh'"

        exit 1
    else

        if [ -z "$Targets" ]; then

            echo "Executing build (via command \`make\`)"
        else

            echo "Executing build (via command \`make\`) with specific target(s) $(join_by , "${Targets[@]}")"
        fi

        make ${Targets[*]}
        status=$?

        cd ->/dev/null

        exit $status
    fi
fi


# ############################## end of file ############################# #

