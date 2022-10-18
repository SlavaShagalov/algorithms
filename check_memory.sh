#!/usr/bin/env bash

# Check if the xml has any "</errorcounts>" attributes. If it has, memory errors exists.

xml_file="unit_tests_valgrind.xml"

sed 's/"/ /g' < $xml_file | grep '</error>' &> /dev/null
if [ $? == 0 ]; then
    printf "%s" "$boldred"
    echo "[  FAILED  ] Some memory checks failed for $xml_file."
    error=-1
        exit $error;
else
    echo "[  SUCCESS  ]"
fi
