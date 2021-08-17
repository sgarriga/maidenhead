#!/bin/bash
#
echo Running self test

echo -n Testing Munich at 48.146660 11.608330 :' '
grid=`./maidenhead 48.146660 11.608330`
exp=JN58td
if [ $exp = $grid ]; then
    echo Passed
else
    echo Failed - expected $exp, got $grid
fi

echo -n Testing Montevideo at -34.910000 -56.211660 :' '
grid=`./maidenhead -34.910000 -56.211660`
exp=GF15vc
if [ $exp = $grid ]; then
    echo Passed
else
    echo Failed - expected $exp, got $grid
fi

echo -n Testing Washington, DC at 38.920000 -77.065000 :' '
grid=`./maidenhead 38.920000 -77.065000`
exp=FM18lw
if [ $exp = $grid ]; then
    echo Passed
else
    echo Failed - expected $exp, got $grid
fi

echo -n Testing Wellington at -41.283330 174.745000 :' '
grid=`./maidenhead -41.283330 174.745000`
exp=RE78ir
if [ $exp = $grid ]; then
    echo Passed
else
    echo Failed - expected $exp, got $grid
fi

echo -n Testing Newington, CT \(W1AW\) at 41.714775 -72.727260 :' '
grid=`./maidenhead 41.714775 -72.727260`
exp=FN31pr
if [ $exp = $grid ]; then
    echo Passed
else
    echo Failed - expected $exp, got $grid
fi
echo -n Testing Palo Alto \(K6WRU\) at 37.413708 -122.107324 :' '
grid=`./maidenhead 37.413708 -122.107324`
exp=CM87wj
if [ $exp = $grid ]; then
    echo Passed
else
    echo Failed - expected $exp, got $grid
fi

