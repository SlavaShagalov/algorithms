#!/usr/bin/env bash

# Check if the xml has any "</errorcounts>" attributes. If it has, memory errors exists.

xml_file="unit_tests_valgrind.xml"

if [ ! -f "$xml_file" ]; then
    echo "[ FAILED ]: $xml_file does not exist."
    exit 2
fi

sed 's/"/ /g' < $xml_file | grep '</error>' &> /dev/null
if [ $? == 0 ]; then
    printf "%s" "$boldred"
    echo "[ FAILED ]: Some memory checks failed for $xml_file."
    exit 1
else
    echo "[ SUCCESS ]: No leaks found"
fi
