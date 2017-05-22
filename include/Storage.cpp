#include "Meeting.hpp"
#include "User.hpp"
#include <functional>
#include <list>
#include <memory>
#include <string>


  /**
  *   default constructor
  */
  Storage();

  /**
  *   read file content into memory
  *   @return if success, true will be returned
  */
  bool readFromFile(void);

  /**
  *   write file content from memory
  *   @return if success, true will be returned
  */
  bool writeToFile(void);

public:
  /**
  * get Instance of storage
  * @return the pointer of the instance
  */
	std::shared_ptr<Storage> Storage::getInstance(void)
 	{
  		return m_instance;
  	} 

  /**
  *   destructor
  */
  Storage::~Storage();

  // CRUD for User & Meeting
  // using C++11 Function Template and Lambda Expressions

  /**
  * create a user
  * @param a user object
  */
  void Storage::createUser(const User & t_user)
  {
  	m_userList.push_back(t_user);
  }

  /**
  * query users
  * @param a lambda function as the filter
  * @return a list of fitted users
  */
  std::list<User> Storage::queryUser(std::function<bool(const User &)> filter) const
  {
  	
  }

  /**
  * update users
  * @param a lambda function as the filter
  * @param a lambda function as the method to update the user
  * @return the number of updated users
  */
  int Storage::updateUser(std::function<bool(const User &)> filter,
                 std::function<void(User &)> switcher);

  /**
  * delete users
  * @param a lambda function as the filter
  * @return the number of deleted users
  */
  int Storage::deleteUser(std::function<bool(const User &)> filter);

  /**
  * create a meeting
  * @param a meeting object
  */
  void Storage::createMeeting(const Meeting & t_meeting)
  {
  	m_meetingList.push_back(t_meeting);
  }

  /**
  * query meetings
  * @param a lambda function as the filter
  * @return a list of fitted meetings
  */
  std::list<Meeting> Storage::queryMeeting(std::function<bool(const Meeting &)> filter) const;

  /**
  * update meetings
  * @param a lambda function as the filter
  * @param a lambda function as the method to update the meeting
  * @return the number of updated meetings
  */
  int Storage::updateMeeting(std::function<bool(const Meeting &)> filter,
                    std::function<void(Meeting &)> switcher);

  /**
  * delete meetings
  * @param a lambda function as the filter
  * @return the number of deleted meetings
  */
  int Storage::deleteMeeting(std::function<bool(const Meeting &)> filter);

  /**
  * sync with the file
  */
  bool Storage::sync(void);

private:
  static std::shared_ptr<Storage> m_instance;
  std::list<User> m_userList;
  std::list<Meeting> m_meetingList;
  bool m_dirty;
};
