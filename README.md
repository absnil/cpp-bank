# cpp-bank

This is a basic bank system project in C++.
Google Protocol Buffers are used for serialization and deserialization of data into files
The project is aimed at mucking around with protobuf and getting hands dirty with c++.
A lot of things may feel like overkill, but its just to try a bunch of different things out

To run locally:
1. pull down files
2. generate protobuf files using command:
    protoc --cpp_out=. account_system.proto
3. create object file using command: 
    g++ -o bank_app main.cxx banking.h banking.cxx account_system.pb.cc transactions.h transactions.cxx `pkg-config --cflags --libs protobuf`