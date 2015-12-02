#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu" ]]; then
 	sudo apt-get install libcppunit-dev
elif [[ "$OSTYPE" == "darwin"* ]]; then
	brew install cppunit
fi
