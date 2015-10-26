#include "distData.h"  // As an example
#include <iostream>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace comProto;

int main(int argc, char **argv) {
  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  distDataClient client(protocol);
  transport->open();
  client.ping();
  directory myDir;
  client.listFilesDir(myDir,"/home/ajonen8940/","");
  std::cout << "here: " << std::endl; 
  for (std::vector<file>::iterator it = myDir.files.begin();it!=myDir.files.end();++it){
         std::cout <<"filename: " <<  it->name << std::endl;
  }
   
// result feedBack;
// client.runCmd(feedBack,"ls -al");
  transport->close();

  return 0;
}
