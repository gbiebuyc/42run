#!/bin/bash
pushd include/ >/dev/null
echo -e "#ifndef $(echo $1 | tr a-z A-Z)_HPP
#define $(echo $1 | tr a-z A-Z)_HPP\n
#include <iostream>\n
class $1 {
public:\n
private:\n
};\n
#endif" >> $1.hpp
popd >/dev/null
pushd src/ >/dev/null
echo -e "#include <$1.hpp>\n" >> $1.cpp
popd >/dev/null
