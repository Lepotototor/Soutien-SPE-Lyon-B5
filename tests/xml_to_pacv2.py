#!/usr/bin/env python3

import xml.etree.ElementTree as ET
import sys

if len(sys.argv) != 3:
    print("Usage: python convert_criterion_to_pacv2.py input.xml output.xml")
    sys.exit(1)

input_file, output_file = sys.argv[1], sys.argv[2]

tree = ET.parse(input_file)
root = tree.getroot()

out_root = ET.Element("testsuites")
out_suite = ET.SubElement(out_root, "testsuite")

for suite in root.findall("testsuite"):
    for case in suite.findall("testcase"):
        name = case.get("name", "unknown")
        status = case.get("status", "")
        classname = suite.get("name", "exercise.tests")

        out_case = ET.SubElement(out_suite, "testcase", {
            "name": name,
            "classname": classname,
            "time": case.get("time", "0.0"),
            "zluor_idx": "0"
        })

        if status != "PASSED":
            failure_elem = case.find("failure")
            failure = ET.SubElement(out_case, "failure")

            if failure_elem is not None:
                if failure_elem.get("type"):
                    failure.set("type", failure_elem.get("type"))
                if failure_elem.get("message"):
                    failure.set("message", failure_elem.get("message"))

                # On remplace les CR/LF en texte brut
                failure.text = (failure_elem.text or "").strip()
            else:
                failure.text = f"Test {name} failed in suite {classname}"

tree_out = ET.ElementTree(out_root)
ET.indent(tree_out, space="  ")

xml_bytes = ET.tostring(out_root, encoding='utf-8')
xml_str = xml_bytes.decode('utf-8')

xml_str = xml_str.replace('&amp;#10;', '\n')

# Écrire avec déclaration XML en tête
with open(output_file, 'w', encoding='utf-8') as f:
    f.write('<?xml version="1.0" encoding="UTF-8"?>\n')
    f.write(xml_str)
