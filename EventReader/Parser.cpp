#include "Parser.h"
#include <iostream>
#include <boost/lexical_cast.hpp>

Parser::Parser(void)
{
}


Parser::~Parser(void)
{
}
string Parser::parse_numtype(string num)
{
	int num_type = (num.length()<10)+1;
	return boost::lexical_cast<std::string>(num_type);
}
string Parser::format_srcdstnum(string src,string dst)
{
	string result = "&src_num=";
	result+=src;
	result+="&src_type=";
	result+=parse_numtype(src);
	result+="&dst_num=";
	result+=dst;
	result+="&dst_type=";
	result+=parse_numtype(dst);
	return result;
}
string Parser::parse_initcall(string src,string dst,string uid,string timestamp,string callid)
{
	

	string request = "http://sipuni.com/native/crmtest.php?userId=";
	request+=uid;
	request+="&event=1&call_id=";
	request+=callid;
	request+=format_srcdstnum(src,dst);
	request+="&timestamp=";
	request+=timestamp;
	return request;
}
string Parser::parse_outcall(string src,string dst,string uid,string timestamp,string callid)
{
	string request = "http://sipuni.com/native/crmtest.php?userId=";
	request+=uid;
	request+="&event=1&call_id=";
	request+=callid;
	request+=format_srcdstnum(src,dst);
	request+="&timestamp=";
	request+=timestamp;
	return request;
}
string Parser::parse_incomecall(string src,string dst,string uid,string timestamp,string callid,string srctype)
{

	string request = "http://sipuni.com/native/crmtest.php?userId=";
	request+=uid;
	request+="&event=1&call_id=";
	request+=callid;
	request+=format_srcdstnum(src,dst);
	request+="&timestamp=";
	request+=timestamp;
	return request;
}

string Parser::parse_answercall(string src,string dst,string uid,string timestamp,string callid,string calltype)
{
	int src_type = (src.length()<10)+1;
	int dst_type = (dst.length()<10)+1;
	
	string request = "http://sipuni.com/native/crmtest.php?userId=";
	request+=uid;
	request+="&event=3&call_id=";
	request+=callid;
	request+=format_srcdstnum(src,dst);
	/*if((calltype=="out")||(calltype=="local"))
		request+="&src_type=2&dst_num=";
	else
		request+="&src_type=1&dst_num=";

	request+=dst;
	if(calltype=="out")
		request+="&dst_type=1&timestamp=";
	else
		request+="&dst_type=2&timestamp=";*/

	request+="&timestamp=";
	request+=timestamp;
	return request;
}

string Parser::parse_finishcall(string src,string dst,string uid,string timestamp,string callid,string callstart,string callanswer,string status,string calltype)
{

	string request = "http://sipuni.com/native/crmtest.php?userId=";
	request+=uid;
	request+="&event=2&call_id=";
	request+=callid;
	/*request+="&src_num=";
	request+=src;
	if((calltype=="out")||(calltype=="local"))
		request+="&src_type=2&dst_num=";
	else
		request+="&src_type=1&dst_num=";

	request+=dst;*/
	
	/*if(calltype=="out")
		request+="&dst_type=1&call_start_timestamp=";
	else
		request+="&dst_type=2&call_start_timestamp=";
	*/
	request+=format_srcdstnum(src,dst);
	request+="&call_start_timestamp=";
	request+=callstart;
	request+="&call_answer_timestamp=";
	request+=callanswer;
	request+="&timestamp=";
	request+=timestamp;
	request+="&status=";
	request+=status;
	request+="&call_record_link=unknown";

	//cout<<"finish"<<request<<endl;
	return request;
}
string Parser::parse_transfercall(string src,string dst,string uid,string timestamp,string callid)
{
	string request = "http://sipuni.com/native/crmtest.php?userId=";
	request+=uid;
	request+="&event=1&call_id=";
	request+=callid;
	request+=format_srcdstnum(src,dst);
	request+="&timestamp=";
	request+=timestamp;
	return request;

}


string Parser::parsedata(map<string,string>& data)
{
	string str = "";
	if(data["Event:"]=="UserEvent")
	{
		if(data["UserEvent:"]=="incomecall")
		{
			 str = parse_incomecall(data["src"],data["dst"],data["userid"],data["time"],data["Uniqueid:"],data["srctype"]);
			
		}
		if(data["UserEvent:"]=="outcall")
		{
			 str = parse_outcall(data["src"],data["dst"],data["userid"],data["time"],data["Uniqueid:"]);
			
		}
		if(data["UserEvent:"]=="answercall")
		{
			 str = parse_answercall(data["src"],data["dst"],data["userid"],data["time"],data["callid"],data["calltype"]);
			
		}
		if(data["UserEvent:"]=="initcall")
		{
			 str = parse_initcall(data["src"],data["dst"],data["userid"],data["time"],data["Uniqueid:"]);
			
		}
		if(data["UserEvent:"]=="transfercall")
		{
			str = parse_initcall(data["src"],data["dst"],data["userid"],data["time"],data["CallUniq"]);
			
		}
		if(data["UserEvent:"]=="finishcall")
		{
			 str = parse_finishcall(data["src"],data["dst"],data["userid"],data["time"],data["Uniqueid:"],data["callstart"],data["callanswer"],data["status"],data["calltype"]);
			
		}
	}
	else
		cout<<"wrong event "<<data["Event:"]<<endl;
	
	cout<<"Parse"<<endl<<str<<endl<<endl;
	return str;
}