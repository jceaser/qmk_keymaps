#!/bin/bash


function send()
{
    echo send
    ls -l $1/keyboards/lets_split/keymaps/baltimore
    ls -l $1/keyboards/planck/keymaps/baltimore
}

function recieve()
{
    echo recieve
    ls -l $1/keyboards/lets_split/keymaps/baltimore
    ls -l $1/keyboards/planck/keymaps/baltimore
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
        h) echo help ; exit 0 ;;
    esac
done