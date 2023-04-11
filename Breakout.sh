xhost +local:docker

if [[ "$(docker images -q breakout 2> /dev/null)" == "" ]]; then
  docker build -t breakout .
fi

docker run -d --rm --env="DISPLAY" --net=host breakout

