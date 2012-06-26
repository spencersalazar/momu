// name
"192.168.0.192" => string hostname;
8888 => int port;

// check command line
if( me.args() ) me.arg(0) => hostname;
if( me.args() > 1 ) me.arg(1) => Std.atoi => port;

// send object
OscSend xmit;

// aim the transmitter
xmit.setHost( hostname, port );

// infinite time loop
while( true )
{
    // start the message...
    xmit.startMsg( "/mopho/test", "i f" );

    // a message is kicked as soon as it is complete 
    Std.rand2( 30, 80 ) => xmit.addInt;
    Std.rand2f( .1, .5 ) => xmit.addFloat;

    // advance time
    0.2::second => now;
}
