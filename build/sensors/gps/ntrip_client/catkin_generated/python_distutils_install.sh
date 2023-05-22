#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/dong/Development/SCV/src/sensors/gps/ntrip_client"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/dong/Development/SCV/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/dong/Development/SCV/install/lib/python3/dist-packages:/home/dong/Development/SCV/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/dong/Development/SCV/build" \
    "/usr/bin/python3" \
    "/home/dong/Development/SCV/src/sensors/gps/ntrip_client/setup.py" \
     \
    build --build-base "/home/dong/Development/SCV/build/sensors/gps/ntrip_client" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/dong/Development/SCV/install" --install-scripts="/home/dong/Development/SCV/install/bin"
