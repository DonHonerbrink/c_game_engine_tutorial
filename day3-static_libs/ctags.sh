#!/bin/bash
script=$(readlink -f $0)
scriptpath=`dirname $script`
ctags -R -f $scriptpath/.tags $scriptpath/src $scriptpath/deps
