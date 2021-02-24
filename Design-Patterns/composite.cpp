/*
 * main.cpp
 *
 *  Created on: 30/10/2018
 *      Author: csouza
 */

#include <vector>
#include <iostream>


/* Super Class for files and directories */
class Component{
public:
	std::string name;
	tm *dateCreated;
	tm* dateLastModified;

	Component(std::string n)
	{
		this->name = n;
		this->dateCreated = new tm();
		this->dateLastModified = new tm();
	}
};

/* Creating a file Class */
class File : public Component{
public:
	std::string fileType;
	File(std::string n, std::string f) : Component(n){
		this->fileType = f;
	}
};

/* Creating a folder Class */
class Folder: public Component{
public:
	std::vector<Component>* contends =  new std::vector<Component>();
	Folder(std::string n) : Component(n){

	}
};

int main(int argc, char **argv) {
	Folder *top = new Folder("Top Folder");
	File *a = new File("A", "Spreadsheet");
	File *b = new File("B", "Picture");
	Folder *mid = new Folder("Mid Folder");

	top->contends->push_back(*a);
	top->contends->push_back(*b);
	top->contends->push_back(*mid);

	File *c = new File("C", "Video");
	File *d = new File("D", "Letter Document");
	Folder *bot = new Folder("Bottom Folder");

	mid->contends->push_back(*c);
	mid->contends->push_back(*d);
	mid->contends->push_back(*bot);

	File *e = new File("E", "PDF");
	bot->contends->push_back(*e);

	std::cout <<top->name << "\n";
	for(Component i : *top->contends)
	{
		std::cout << " " << i.name <<"\n";
	}

	for(Component i : *mid->contends)
	{
		std::cout << " " << i.name <<"\n";
	}

	for(Component i : *bot->contends)
	{
		std::cout << " " << i.name <<"\n";
	}

	return 0;
}



