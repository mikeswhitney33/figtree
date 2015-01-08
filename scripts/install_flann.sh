wget http://www.cs.ubc.ca/research/flann/uploads/FLANN/flann-1.8.4-src.zip
unzip flann-1.8.4-src
cd flann-1.8.4-src
mkdir build
cd build
cmake .. -DBUILD_C_BINDINGS=OFF -DBUILD_MATLAB_BINDINGS=OFF -DBUILD_PYTHON_BINDINGS=OFF -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON
make
sudo make install
