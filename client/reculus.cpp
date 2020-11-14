// This For Project reculus Database Memory
// This First Play In App
// Server side C/C++ program to demonstrate Socket programming 
// Copyright 2020 - 2025
// This Server For Database Memorylient side C/C++ program to demonstrate Socket programming

#include "../header/reculus.hpp"
#include "../header/config.hpp"

int main(int argc, char const *argv[]) 
{ 
	std::cout << "Reculus{CLIENT} : Start Now" << std::endl;
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	const char *hello = "Hello from client"; 
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 
	std::cout << "Reculus{CLIENT} : Secure Run" << std::endl;
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
	send(sock , hello , strlen(hello) , 0 ); 
	printf("Hello message sent\n"); 
	valread = read( sock , buffer, 1024); 
	printf("%s\n",buffer ); 
	return 0; 
}
