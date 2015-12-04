#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu" ]]; then
	sudo apt-get update -qq
 	sudo apt-get install -y libcppunit-dev
elif [[ "$OSTYPE" == "darwin"* ]]; then
	brew install cppunit
fi
