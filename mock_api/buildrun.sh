#!/usr/bin/bash
script=$(readlink -f $0)
scriptpath=`dirname $script`

pushd "$scriptpath"
cmake --build "$scriptpath/build"
buildresult=$?


if [ $buildresult -eq 0 ]
then
	exec "$scriptpath/build/game"
fi

popd
exit $buildresult


