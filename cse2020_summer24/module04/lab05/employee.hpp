/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 05
 * Date: June 14, 2027
*/

// employee.hpp
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>

using namespace std;

class Employee {

private:
    int id;
    string name;
    string dept;

public:   

    Employee():id(0),name(""),dept("") {

    }

    Employee(int id, const string &name,  const string &dept):id(id), name(name), dept(dept) {

    }

    int get_id() const {
    	return id;
    }

    string get_name() const {
    	return name;
    }

    string get_dept() const {
    	return dept;
    }

    void set_id(int id) {
    	this->id = id;
    } 

    void set_name(const string &name) {
    	this->name = name;
    } 

    void set_dept(const string &dept) {
        this->dept = dept;
    }

    void print() const {
    	std::cout << get_id() << ", " 
                << get_name() << ", "
                << get_dept() << std::endl;
    }

    friend ostream &operator<<( ostream &output, const Employee &e ) { 
            output <<  e.get_id() << " "<< e.get_name() << " " << e.get_dept();
            return output;            
    }

    friend istream &operator>>( istream &input, Employee &e ) { 
            input >>  e.id >> e.name >> e.dept;
            return input;            
    }

    friend bool operator== (const Employee &e1, const Employee &e2) {
        return (e1.id == e2.id &&
                e1.name == e2.name &&
                e1.dept == e2.dept);
    }

    friend bool operator!= (const Employee &e1, const Employee &e2) {
        return !(e1.id == e2.id &&
                e1.name == e2.name &&
                e1.dept == e2.dept);
    }
    
};

#endif
