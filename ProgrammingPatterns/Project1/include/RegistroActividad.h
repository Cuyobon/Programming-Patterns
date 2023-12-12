#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RegistroActividad {
public:
  /*
    Brief: Constructor for RegistroActividad class.
    Initializes the number of activities to zero.
   */
  RegistroActividad() : m_numActs(0) {}

  /*
   Brief: Static method to obtain an instance of the RegistroActividad class.
   If an instance already exists, returns the existing instance, if not, 
   creates a new instance and returns it.
   */
  static RegistroActividad* getInstance() {
    if (m_instance != nullptr) {
      return m_instance;
    }
    else {
      m_instance = new RegistroActividad;
    }
    return m_instance;
  }

  /**
    Brief: Adds a new activity to the activity log.
    If the maximum number of activities has not been reached,
    adds the activity to the log; otherwise, displays a message
    indicating that the activity log is full.
   */
  void addActivity(const string actividad) {
    if (m_numActs < m_maxActs) {
      //m_acts[m_numActs++] = actividad;
      m_acts.push_back(actividad);
    }
    else {
      cout << "Activity log is full." << endl;
    }
  }

  /*
    Brief: Displays all the activities stored in the activity log.
   */
  void showActivities() {
    cout << "Activity Log:" << endl;
    for (const string actividad : m_acts) {
      //for (int i = 0; i < m_numActs; i++)
      //cout << m_acts[i] << endl;
      cout << actividad << endl;
    }
  }

private:
  static RegistroActividad* m_instance; // Static instance of the class
  static const int m_maxActs = 20; // Maximum number of activities
  //string m_acts[m_maxActs]; // Array to store activities (commented out)
  vector<string> m_acts; // Vector to store activities
  int m_numActs; // Number of activities stored
};
