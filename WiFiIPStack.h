/*******************************************************************************
 * Copyright (c) 2014 Henrik Olsson, henols@gmail.com.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 * 	  Henirk Olsson
 *    Ian Craggs - initial API and implementation and/or initial documentation
 *******************************************************************************/

#ifndef ARDUINOWIFIIPSTACK_H
#define ARDUINOWIFIIPSTACK_H

#include <LWiFi.h>
#include <LWiFiClient.h>

class WiFiIPStack
{
public:    
    WiFiIPStack()
    {
        //WiFi.begin();              // Use DHCP
        iface.setTimeout(1000);    // 1 second Timeout 
    }
    
    int connect(char* hostname, int port)
    {
        return iface.connect(hostname, port);
    }

    int connect(uint32_t hostname, int port)
    {
        return iface.connect(hostname, port);
    }

    int read(unsigned char* buffer, int len, int timeout)
    {
        iface.setTimeout(timeout);
        while(!iface.available());
		size_t l;

        l = iface.readBytes(buffer, len);
        return l;
    }
    
    int write(unsigned char* buffer, int len, int timeout)
    {

    	Serial.println("write to stream");
    	Serial.println(*buffer);
        iface.setTimeout(timeout);
		size_t l;
    	Serial.println("after write");
        l = iface.write((uint8_t*)buffer, len);
        return l;
    }
    
    int disconnect()
    {
        iface.stop();
        return 0;
    }
    
private:

    LWiFiClient iface;

};

#endif



