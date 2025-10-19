#!/bin/sh

./dragons_testsuite --xml=trace.xml >/dev/null
./tests/xml_to_pacv2.py trace.xml trace.xml
