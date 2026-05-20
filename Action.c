Action()
{
	
	int dNmbr;
	int iz;
	float f =10.3;
	double d = 10.34353443;
	long l=23545;
	char *ch;
	
	int arrsize,farrsize;
	char  sInt[15];
	
	int rvalue;
	char *rCity;
	
	char *_Acity;
	char *_Dcity;

	web_add_auto_header("Accept-Language","en-GB,en;q=0.9");

	web_reg_save_param_ex("paramName=C_userSession","LB=userSession\" value=\"","RB=\"/>",LAST);
	web_url("webtours", 
		"URL=http://192.168.29.135:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	
	
	web_set_sockets_option("SSL_VERSION", "AUTO");

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_submit_data("login.pl", 
		"Action=http://192.168.29.135:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://192.168.29.135:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={C_userSession}", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=62", ENDITEM, 
		"Name=login.y", "Value=19", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);
	
	lr_output_message("--------%d",d);
	lr_output_message("--------%s",ch);

	web_reg_save_param_ex("paramName=C_deprt","LB=\">","RB=</option>","ordinal=all",LAST);


	web_reg_save_param_ex(
		"ParamName=C_arrive",
		"LB/IC=\">",
		"RB/IC=</option>",
		"Ordinal=all",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_url("Search Flights Button", 
		"URL=http://192.168.29.135:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://192.168.29.135:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("reservations.pl",
		"Action=http://192.168.29.135:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://192.168.29.135:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={C_deprt}", ENDITEM,
		"Name=departDate", "Value=08/28/2024", ENDITEM,
		"Name=arrive", "Value={C_arrive}", ENDITEM,
		"Name=returnDate", "Value=08/29/2024", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value=None", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=findFlights.x", "Value=61", ENDITEM,
		"Name=findFlights.y", "Value=12", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);
	
	lr_output_message((lr_eval_string("{C_deprt_count}")));
	
	  // string to int convertion
	 arrsize = atoi(lr_eval_string("{C_deprt_count}"));
     lr_output_message("------%d",arrsize);
	
     
	// int to string convertion. method-1
	farrsize=arrsize+1;	
	itoa(farrsize,sInt,10);
	lr_save_string(sInt,"lrsInt");
	lr_output_message(lr_eval_string("{lrsInt}"));
	

    // method -2
   lr_save_int(farrsize,"lr_ch");
   lr_output_message(lr_eval_string("{lr_ch}"));
   
   //Picking a random value from an array.
   rvalue= rand()%arrsize+1;
   rCity =lr_paramarr_idx("C_deprt",rvalue);
   lr_save_string(rCity,"lr_rCity");
   lr_output_message( lr_eval_string("{lr_rCity}"));
   
   //picking  first half values from an array
   rvalue= rand()%(arrsize/2)+1;
   rCity =lr_paramarr_idx("C_deprt",rvalue);
   lr_save_string(rCity,"lr_rCity2");
   lr_output_message( lr_eval_string("{lr_rCity2}"));
   
   //picking last half values from an array
   rvalue= arrsize-(arrsize/2);
   rCity =lr_paramarr_idx("C_deprt",rvalue);
   lr_save_string(rCity,"lr_rCityLH");
   lr_output_message( lr_eval_string("{lr_rCityLH}"));

   
   //picking a last value from an array
   rCity =lr_paramarr_idx("C_deprt",arrsize);
   lr_save_string(rCity,"lr_rCity3");
   lr_output_message( lr_eval_string("{lr_rCity3}"));
	
   //picking a last but not one value from an array
   rCity =lr_paramarr_idx("C_deprt",arrsize-1);
   lr_save_string(rCity,"lr_rCity4");
   lr_output_message( lr_eval_string("{lr_rCity4}"));
	

	//Comparing two C variables.
	_Acity = lr_paramarr_random("C_arrive");
	_Dcity = lr_paramarr_random("C_deprt");
	if(strcmp(_Dcity,_Acity)!=0)
	{
		lr_output_message("Dcity and Acity are not same. Test pass.");
	}
	
	//Comparing two LR variables.
	_Dcity=lr_eval_string("{C_deprt_1}");
	_Acity=lr_eval_string("{C_arrive_2}");
	lr_save_string(_Dcity,"lr_Dcity");
    lr_save_string(_Acity,"lr_Acity"); 

    if(strcmp(lr_eval_string("{lr_Dcity}"),lr_eval_string("{lr_Acity}"))!=0)
	{
	  lr_output_message("Dcity and Acity are not same. Test-2 pass.");

	}
	
   ch =lr_eval_string("{P_vUser}");
    //Book a ticket from alternative users
    if( atoi(lr_eval_string("{P_vUser}"))%2==0)
    {
    	lr_output_message("Sucessfully booked ticket for--",lr_eval_string("{P_vUser}"));
    }
	
	web_submit_data("reservations.pl_2", 
		"Action=http://192.168.29.135:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://192.168.29.135:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=280;1441;08/28/2024", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=55", ENDITEM, 
		"Name=reserveFlights.y", "Value=1", ENDITEM, 
		LAST);
	
    
	
	lr_think_time(4);

	web_submit_data("reservations.pl_3", 
		"Action=http://192.168.29.135:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://192.168.29.135:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=outboundFlight", "Value=280;1441;08/28/2024", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=57", ENDITEM, 
		"Name=buyFlights.y", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_think_time(5);

	web_url("SignOff Button", 
		"URL=http://192.168.29.135:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://192.168.29.135:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}