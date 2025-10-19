#!/bin/sh

./dragons_testsuite --xml=trace.xml >/dev/null
cp trace.xml old.xml
./tests/xml_to_pacv2.py trace.xml trace.xml
