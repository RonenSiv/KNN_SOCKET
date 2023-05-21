

# KNN Machine Learning Algorithm with Socket Programming

Welcome to the KNN Machine Learning Algorithm with Socket Programming README! This project is a C++ implementation of the K-Nearest Neighbors (KNN) machine learning algorithm with the added functionality of socket programming for smooth communication and interaction with clients.


## Supported Distance Metrics

- 📐 **Euclidean Distance** 📐

  ![Euclidean Distance](https://latex.codecogs.com/gif.latex?%5Cinline%20d%28p%2Cq%29%3D%5Csqrt%7B%28p_1-q_1%29%5E2%2B%28p_2-q_2%29%5E2%2B%5Ccdots%2B%28p_i-q_i%29%5E2%2B%5Ccdots%2B%28p_n-q_n%29%5E2%7D)

- 📐 **Manhattan Distance** 📐

  ![Manhattan Distance](https://latex.codecogs.com/gif.latex?%5Cinline%20d%28%5Cmathbf%7Bp%7D%2C%5Cmathbf%7Bq%7D%29%3D%5Cleft%5C%7C%5Cmathbf%7Bp%7D-%5Cmathbf%7Bq%7D%5Cright%5C%7C_%7B1%7D%3D%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%5Cleft%7Cp_i-q_i%5Cright%7C)

- 📐 **Chebyshev Distance** 📐

  ![Chebyshev Distance](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Clim_%7Bp%5Cto%20%5Cinfty%7D%7B%5Cbigg%20%28%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%5Cleft%7Cx_i-y_i%5Cright%7C%5E%7Bp%7D%7D%7B%5Cbigg%20%29%7D%5E%7B1/p%7D)

- 📐 **Canberra Distance** 📐

  ![Canberra Distance](https://latex.codecogs.com/gif.latex?%5Cinline%20d%28%5Cmathbf%7Bp%7D%2C%5Cmathbf%7Bq%7D%29%3D%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%7B%5Cfrac%7B%7Cp_i-q_i%7C%7D%7B%7Cp_i%7C%2B%7Cq_i%7C%7D%7D)

- 📐 **Minkowski Distance** 📐

  ![Minkowski Distance](https://latex.codecogs.com/gif.latex?%5Cinline%20d%5Cleft%28x%2Cy%5Cright%29%3D%5Cleft%28%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%7Cx_i-y_i%7C%5E%7Bp%7D%5Cright%29%5E%7B%5Cfrac%7B1%7D%7Bp%7D%7D)


## Features

- **K-Nearest Neighbors**: Implement the KNN machine learning algorithm to classify data based on the nearest neighbors.
- **Socket Programming**: Utilize socket programming to establish communication channels and interact with clients.
- **Client-Server Architecture**: Enable multiple clients to connect and send data for classification using the KNN algorithm.
- **Real-Time Classification**: Perform real-time classification of data sent by clients using the trained KNN model.
- **Customization**: Adjust the K value, distance metric, and other parameters to fine-tune the KNN algorithm.

## How to Use

1. Clone the repository to your local machine.
2. Compile the C++ code using the makefile provided (or any other compiler).
3. Start the server application by running the executable.
4. Clients can connect to the server using the provided IP address and port number.
5. Clients can send data to the server for classification.
6. The server performs classification using the KNN algorithm and sends the results back to the clients.
7. Analyze the classification results and evaluate the performance of the KNN model.

## Technologies Used

- C++
- Socket Programming


### ![img](https://i.imgur.com/gNdDOCF.gif)UML Diagrams
```mermaid
classDiagram

Distance <|-- EuclideanDistnace
Distance <|-- ManhattanDistnace
Distance <|-- ChebyshevDistnace
Distance <|-- CanberraDistnace
Distance <|-- MinkowskiDistnace

class Distance{
    +Calculate(vector<double>, vector<double>) double
    +validateVectors(vector<double>, vector<double>) void
}

class EuclideanDistnace {
	+Calculate(vector<double>, vector<double>) double
}

class ManhattanDistnace {
	+Calculate(vector<double>, vector<double>) double
}

class ChebyshevDistnace {
	+Calculate(vector<double>, vector<double>) double
}

class CanberraDistnace {
	+Calculate(vector<double>, vector<double>) double
}

class MinkowskiDistnace {
	+Calculate(vector<double>, vector<double>) double
}

```
```mermaid
classDiagram

  

TCPServer o-->  CLI

TCPClient o-->  CLI

CLI o-->  Command

Command  <|--  UploadCommand

Command  <|--  AlgorithmCommand

Command  <|--  ClassifyCommand

Command  <|--  DisplayCommand

Command  <|--  DownloadCommand

Command  <|--  ExitCommand

Command o-->  DefaultIO

DefaultIO  <|--  StandartIO

DefaultIO  <|--  SocketIO

  

class  CLI{

-Command *_command

-DefaultIO *_dio

-string _commandDescription

+start()  void

+getDio()  DefaultIO*

+setDio(DefaultIO *)  void

+setCommand(Command *)  void

+setCommandDescription(string)  void

+getCommandDescription()  string

+getBuffer()  string

+read()  string

+write(string)  void

+emptyBuffer()  void

}

class  Command{

#string commandDescription

#DefaultIO* dio

+execute()  virtual void

+setCommandDescription(std::string commandDescription)  void

+getCommandDescription()  string

+setDio(DefaultIO *dio)  void

+getDio()  DefaultIO*

}

  

class  DefaultIO{

#vector < string > _content

#string _buffer;

#int _messageSize

+read()  virtual string

+write(string)  virtual void

+setMessageSize(int)  void

+getMessageSize()  int

+readFromFile(basic_string< char >)  bool

+writeToFile(const basic_string< char >&, string &)  bool

+getLine(int)  string

+setBuffer(basic_string< char >)  void

+emptyBuffer()  void

+getBuffer()  string

+addLineToContent(const basic_string< char > &)  void

+copyContentTo(vector< string > &)  void

+getContent()  vector< string >

}

```

### ![img](https://i.imgur.com/kgRH2Yn.gif)Accepted Input from client
The following input discuss about the input of the user inside the client side (menu options)
|Menu Option|Description                  |
|Menu Option|Description|
|--------------------------------|-----------------------------|
|`1`|User will be asked to upload a local `train file` and then a local `test file`. make sure the file exists and not empy otherwise server will reject the upload input
|`2`|User will be asked to enter a `k` value and a `distance algorith`, make sure that `k` is greater then 0 and that the distance algorithm is one of the follow input **`AUC`** for Euclidean, **`MAN`** for Manhattan, **`CHB`** for Chebyshev's, **`CAN`** for canberra, **`MIN`** for minkowski.
|`3`|Server will `classify` the `test file` based on the `train file`. make sure that you first upload the data, if for any reason the data is corrupt (meaning you entered strings where numbers should have been inside the train file), the KNN algorithm will refer to those values as the value `0`. if the data inside the test file does not match the data inside the train file the server will output an error to the user about that. The error may very based on the why the classification resulted in an error
|`4`|Server will send to client the `classified` data and the client will print it to the user. Make sure to first upload and classify the data other wise a message will be thrown to the user. After reciving the data the server will wait for user to press `enter` before printing the menu again.
|`5`|Server will ask the user to input a download `file` and in return the server will download the `classified` data inside that `file` **be aware that any data inside this file will be over-written!**. If for any reason the download failed or couldn`t take place, server will output a message to the user.
|`8`|The connection to the server will be `terminated`, and all data regards the user in the server will be `lost`.



## ![img](https://i.imgur.com/SOOMHcv.gif)Files Structure 
```
.
├──app
│	├──header
│	│	├── CLI.h
│	│	├── Command.h
│	│	├── DefaultIO.h
│	│	└── StandartIO.h
│	└──src
│		├── CLI.cpp
│		├── Command.cpp
│		├── DeaultIO.cpp
│		└── StandartIO.cpp		
├── server
│	├── ServerSide.cpp
│	├── ServerSide.h
│	├── src
│	│	├── DIO
│	│	│	└── SocketIO.cpp
│	│	├── commands
│	│	│	├── AlgoSetCommand.cpp
│	│	│	├── ClassifyDataCommand.cpp
│	│	│	├── ExitCommand.cpp
│	│	│	├── SendFileCommand.cpp
│	│	│	└── UploadCommand.cpp
│	│	├── distance
│	│	│	├── Distance.cpp
│	│	│	├── CanberraDistance.cpp
│	│	│	├── MinkowskiDistance.cpp
│	│	│	├── EuclideanDistance.cpp
│	│	│	├── ChebyshevDistance.cpp
│	│	│	└── ManhattanDistance.cpp
│	│	├── factory
│	│	│	├── DistanceFactory.cpp
│	│	│	└── ServerCommandFactory.cpp
│	│	├── util
│	│	│	├── Util.cpp
│	│	│	├── Fanctor.cpp
│	│	│	└── Manager.cpp
│	│	├── database
│	│	│	├── Classification.cpp
│	│	│	└── DataBase.cpp
│	│	└── TCP
│	│		└── TCP_Server.cpp
│	│
│	└── header
│		├── DIO
│		│	└── SocketIO.h
│		├── commands
│		│	├── AlgoSetCommand.h
│		│	├── ClassifyDataCommand.h
│		│	├── ExitCommand.h
│		│	├── SendFileCommand.h
│		│	└── UploadCommand.h
│		├── distance
│		│	├── Distance.h
│		│	├── CanberraDistance.h
│		│	├── MinkowskiDistance.h
│		│	├── EuclideanDistance.h
│		│	├── ChebyshevDistance.h
│		│	└── ManhattanDistance.h
│		├── factory
│		│	├── DistanceFactory.h
│		│	└── ServerCommandFactory.h
│		├── util
│		│	├── Util.h
│		│	├── Fanctor.h
│		│	└── Manager.h
│		├── database
│		│	├── Classification.h
│		│	└── DataBase.h
│		└── TCP
│			└── TCP_Server.h
│	
│
└── client
	├── ClientSide.cpp 
	├── ClientSide.h
	├── src
	│	├── Command
	│	│	├── ClientAlgorithCommand.cpp
	│	│	├── ClientClassifyCommand.cpp
	│	│	├── ClientDisplayCommand.cpp
	│	│	├── ClientDownloadCommand.cpp
	│	│	├── ClientUploadCommand.cpp
	│	│	├── ClientExitCommand.cpp
	│	│	└── ClientCommandFactory.cpp
	│	├── TCP
	│	│	└── TCPClient.cpp
	│	└── Manager
	│		└── ClientManager.cpp
	└── header
		├── Command
		│	├── ClientAlgorithCommand.h
		│	├── ClientClassifyCommand.h
		│	├── ClientDisplayCommand.h
		│	├── ClientDownloadCommand.h
		│	├── ClientUploadCommand.h
		│	├── ClientExitCommand.h
		│	└── ClientCommandFactory.h
		├── TCP
		│	└── TCPClient.h
		└── Manager
			└── ClientManager.h
```

## ![img](https://i.imgur.com/BDXmrJn.gif)Compiling and Running

#### Compiling using makefile

```
make
./server.out port
./client.out ip port
```
make sure ip/port are correct otherwise an error will be thrown and the program will return 1 and close.
  

## ![A](https://i.imgur.com/DngGyzv.gif)Authors
- [@RonenSiv](https://www.github.com/RonenSiv)

- [@Ofirhelerman](https://www.github.com/Ofirhelerman)
