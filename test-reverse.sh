#! /bin/bash

if ! [[ -x reverse ]]; then
    echo "reverse executable does not exist"
    exit 1
fi

cp reverse tests/reverse
cd tests
./tester/run-tests.sh $*
rm reverse
cd ..