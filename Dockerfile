FROM kovenas/sfml
COPY . /AlgoVisual
WORKDIR /AlgoVisual/src/
RUN g++ -o algov main.cpp
CMD ["./algov"]