#!/bin/bash

function help()
{
    echo the avr compile chain seems to not respect symlinks so I can not hack \
    an existing project into a standard QMK repository. This script copies to \
    and from a repository to get around that. This project will be replaced at \
    some point.
    
    echo
    
    template="%10s - %-10s : %s\n"
    
    printf "${template}" "flag" "meaning" "description"
    printf "${template}" "----" "-------" "-----------"
    
    printf "${template}" "s <path>" "send" \
        "copy files from here into a repository"
    printf "${template}" "r <path>" "recieve" \
        "copy files from a repository to here"
    printf "${template}" "d <path>" "difference" \
        "check for changes"
    printf "${template}" "h" "help" \
        "this help"
}

function send()
{
    echo send
    
    cp -rn lets_split/baltimore $1/keyboards/lets_split/keymaps/.
    cp -rn planck/baltimore $1/keyboards/planck/keymaps/.
}

function recieve()
{
    echo recieve

    cp -rn $1/keyboards/lets_split/keymaps/. lets_split/baltimore
    cp -rn $1/keyboards/planck/keymaps/. planck/baltimore
}

function difference()
{
    echo status of lets_split in $1
    diff -r $1/keyboards/lets_split/keymaps/baltimore lets_split/baltimore
    echo

    echo status of planck in $1
    diff -r $1/keyboards/planck/keymaps/baltimore planck/baltimore
    echo
}

while getopts "s:r:d:h" opt ; do
    case "${opt}" in
        s) send ${OPTARG} ; exit 0 ;;
        r) recieve ${OPTARG} ; exit 0 ;;
        d) difference ${OPTARG} ; exit 0 ;;
        h) help ; exit 0 ;;
    esac
done