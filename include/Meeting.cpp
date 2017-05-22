#include "Date.hpp"
#include "Meeting.hpp"
#include <vector>
#include <string>
  Meeting::Meeting(std::string t_sponsor, std::vector<std::string> t_participator, Date t_startTime,
          Date t_endTime, std::string t_title)
          {
          	m_sponsor=t_sponsor;
  			m_participators.assign(t_participator.begin(),t_participator.end());
 			m_startDate=t_startTime;
 			m_endDate=t_endTime;
  			m_title=t_title;
		  }

  Meeting::Meeting(const Meeting &t_meeting)
	{
		m_sponsor=t_meeting.getSponsor();
  		m_participators.assign(t_meeting.getParticipator().begin(),t_meeting.getParticipator().end());
 		m_startDate=t_meeting.getStartDate();
 		m_endDate=t_meeting.getEndDate();
  		m_title=t_meeting.getTitle();
	}
std::string Meeting::getSponsor(void) const
  {
  	return m_sponsor;
  }
  void Meeting::setSponsor(const std::string t_sponsor)
  {
  	m_sponsor=t_sponsor;
  }
  std::vector<std::string> Meeting::getParticipator(void) const
  {
  	return m_participators;
  }
  void Meeting::setParticipator(const std::vector<std::string> t_participators)
  {
  	m_participators.assign(t_participators.begin(),t_participators.end());
  }
  Date Meeting::getStartDate(void) const
  {
  	return m_startDate;
  }
  void Meeting::setStartDate(const Date t_startTime)
  {
  	m_startDate=t_startTime;
  }
  Date Meeting::getEndDate(void) const
{
	return m_endDate;
}
  void Meeting::setEndDate(const Date t_endTime)
{
	m_endDate=t_endTime;
}
  std::string Meeting::getTitle(void) const
{
	return m_title;
}
  void Meeting::setTitle(const std::string t_title)
{
	m_title=t_title;
}
  bool Meeting::isParticipator(const std::string t_username) const
  {
  	auto it=m_participators.begin();
	for(it=m_participators.begin();it!=m_participators.end();it++)
	{
		if((*it)==t_username) break;
	}
	if (it!=m_participators.end())
	{
		return true;
	}
	else
	{
		return false;
	}
  }
