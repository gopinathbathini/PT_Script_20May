Action()
{

	

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-GB,en;q=0.9");
	
lr_start_transaction("Pets_Launch");
	
	web_url("pets.shaft.com", 
		"URL=http://pets.shaft.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Pets_Launch",LR_AUTO);
	
	
	lr_rendezvous("R_FindOwner");
	
	lr_start_transaction("Pets_FindOwner");

	web_url("Find owners", 
		"URL=http://pets.shaft.com/owners/find", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	lr_think_time(4);

	web_submit_data("owners", 
		"Action=http://pets.shaft.com/owners", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/find", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=lastName", "Value=arjun", ENDITEM, 
		LAST);

	web_url("allu arjun", 
		"URL=http://pets.shaft.com/owners/2111", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners?lastName=arjun", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Pets_FindOwner",LR_AUTO);

	lr_start_transaction("Pets_Editowner");

	web_url("Edit Owner", 
		"URL=http://pets.shaft.com/owners/2111/edit", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/2111", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("edit", 
		"Action=http://pets.shaft.com/owners/2111/edit", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/2111/edit", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=allu", ENDITEM, 
		"Name=lastName", "Value=arjun", ENDITEM, 
		"Name=address", "Value=jublihills_RoadNo6", ENDITEM, 
		"Name=city", "Value=hyd", ENDITEM, 
		"Name=telephone", "Value=984893773", ENDITEM, 
		LAST);

	lr_end_transaction("Pets_Editowner",LR_AUTO);

	return 0;
}