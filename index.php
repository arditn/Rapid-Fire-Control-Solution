<?php



	include ( "./src/NexmoMessage.php" );



$num;

if(($fp=fopen("Document.txt", "r")))
{
	while(!feof($fp))
	{
		$contents=fgets($fp);
	}
	$num=$contents;
}

if($num==1)
{
	$num=0;
	file_put_contents("Document.txt",$num);
}
else if($num==0)
{
	$num=1;
	file_put_contents("Document.txt",$num);
	
	//write in file instead sms
	$t=time();
	file_put_contents("Poraki.txt",$t,FILE_APPEND);
	file_put_contents("Poraki.txt","\n",FILE_APPEND);
	
	// Step 1: Declare new NexmoMessage.
	$nexmo_sms = new NexmoMessage('93515d1d', 'ogXZ1wujTHiafuod');

	// Step 2: Use sendText( $to, $from, $message ) method to send a message. 
	$info = $nexmo_sms->sendText( '+38978605505', 'Ivana', 'Fire in HOTEL INEX GORICA OHRID. There are 45 people stuck inside the building' );

	// Step 3: Display an overview of the message
	echo $nexmo_sms->displayOverview($info);

	// Done!
}
?>