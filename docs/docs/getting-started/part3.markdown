---
layout: default
title: Getting Started Guide
prev: /docs/getting-started/part2
next: /docs/getting-started/part4
---

# Part 3: How to Run a Simulated Build

1. Start B&R Automation Studio.
2. Navigate to `reAM250plcOpen` and open the Automation Studeo Project `./reAM250plc.apj`
3. Switch to simulation mode.
4. Build and transfer the project to the simulated target
5. Ensure the connection settings of the simulated target are set correctly
	- IP adress: 127.0.0.1 
	- Port: 12200
6. Navigate to the `AMCF/output` folder and run the server executable `./amc_server.exe`.
7. Open the UI in the browser [http://localhost:8869/](http://localhost:8869/)

### How to Connect to the Hardware

By default, the simulation mode is activated to run the above simulated build.
To change this and connect to a real target, the config file has to be adapted. 

#### To adapt the config file
- Open the AMCF Visual Studio Solution `AMCF/build/reAM250.sln`
- Open the `config.xml`

#### To connect to a PLC 
- Adjust the connection settings to your hardware; statemachine: plc -> parametergroup: configuration -> parameter: ipadress and parameter: port
- Disable the simulation mode by setting the default value to 0; statemachine: plc -> parametergroup: simulation -> parameter: plc_is_simulated

#### To connect the scanner control board
- Adjust the card configuration according to your hardware; statemachine: scanner -> parametergroup: cardconfig -> parameter: cardtype, parameter: serial, parameter: ipaddress, parameter: netmask, and parameter: port
- Disable the simulation mode by setting the default value to 0; statemachine: scanner -> parametergroup: cardconfig -> parameter: simulatelaser


---

<div class="chapter-nav">
  <a href="{{ page.prev | relative_url }}">Prev</a>
  <a href="{{ '/docs/getting-started/' | relative_url }}">Getting Started – Table of Contents</a>
  <a href="{{ page.next | relative_url }}">Next</a>
</div>
