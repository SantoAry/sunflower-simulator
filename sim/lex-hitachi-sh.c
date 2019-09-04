/*
	Copyright (c) 1999-2008, Phillip Stanley-Marbell (author)
 
	All rights reserved.

	Redistribution and use in source and binary forms, with or without 
	modification, are permitted provided that the following conditions
	are met:

	*	Redistributions of source code must retain the above
		copyright notice, this list of conditions and the following
		disclaimer.

	*	Redistributions in binary form must reproduce the above
		copyright notice, this list of conditions and the following
		disclaimer in the documentation and/or other materials
		provided with the distribution.

	*	Neither the name of the author nor the names of its
		contributors may be used to endorse or promote products
		derived from this software without specific prior written 
		permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
	FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
	COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
	ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
	POSSIBILITY OF SUCH DAMAGE.
*/

/*									*/
/*	Lexical Analyser for asm parser. Defines yylex() for use 	*/
/*	by yyparse(), generated by Bison/Yacc from shasm.y		*/
/*	NOTE : This file is '#'included from shasm.y, so we already 	*/
/*	have <string.h> etc included.					*/
/*									*/

typedef struct
{
	char 	*token;
	ushort	token_value;
} TokenTab;

/*									*/
/*	See mkhelp script for how help and LaTeX is generated from	*/
/*	from this file. NOTE '*', '_', '}', '{', plus, ',' and ':', '"' */
/*	have special meaning in the comments which are marked w/ plus, 	*/
/*	so do not use them. These comments are used to build "help.h"	*/
/*	and also to generate LaTeX for the manual.			*/
/*									*/
TokenTab superH_token_table [] =
{
	/*	Simulator Commands	*/
	{"RUN",		T_RUN},					/*+	Mark a node as runnable.:none											*/
	{"CACHEINIT",	T_CACHEINIT},				/*+	Initialise cache.:<cache size (integer)> <block size (integer)> <set associativity (integer)>			*/
	{"CACHEOFF",	T_CACHEOFF},				/*+	Deactivate cache.:none 												*/
	{"CACHESTATS",	T_CACHESTATS},				/*+	Retrieve cache access statistics.:none										*/
	{"C",		T_CACHESTATS},				/*+	Synonym for CACHESTATS.:none											*/
	{"CA",		T_MODECA},				/*+	Set simulator in cycle-accurate mode.:none									*/
	{"FF",		T_MODEFF},				/*+	Set simulator in fast functional mode.:none									*/
	{"MMAP",	T_MMAP},				/*+	Map memory of one simulated node into another.:<source (integer)> <destination (integer)>			*/
	{"DUMPREGS",	T_DUMPREGS},				/*+	Show the contents of the general purpose registers.:none							*/
	{"DUMPSYSREGS",	T_DUMPSYSREGS},				/*+	Show the contents of the system registers.:none									*/
	{"DUMPMEM",	T_DUMPMEM},				/*+	Show contents of memory.:<start mem address (hexadecimal)> <end mem address (hexadecimal)>			*/
	{"DUMPPIPE",	T_DUMPPIPE},				/*+	Show the contents of the pipeline stages.:none									*/
	{"DUMPDISTR",	T_DUMPDISTRIBUTION},			/*+	Show the number of times each instruction was run.:none								*/
	{"RESETCPU",	T_RESETCPU},				/*+	Reset entire simulated CPU state.:none										*/ 
	{"SAVE",	T_SAVE},				/*+	Dump memory region to disk.:<start mem addr (hexadecimal)> <end mem addr (hexadecimal)> <filename (string)>	*/
	{"SETVDD",	T_SETVDD},				/*+	Set operating voltage from frequency.:<Vdd/volts (real)>							*/
	{"SETFREQ",	T_SETFREQ},				/*+	Set operating frequency from voltage.:<freq/MHz (real)>								*/
	{"SETMEMBASE",	T_SETMEMBASE},				/*+	Set base address of simulator memorry array.:<address (integer)>						*/
	{"SHOWMEMBASE",	T_SHOWMEMBASE},				/*+	Show base address of simulator memorry array.:none								*/
	{"PD",		T_DISABLEPIPELINE},			/*+	Disable simulation of processor's pipeline.:none								*/
	{"PE",		T_ENABLEPIPELINE},			/*+	Enable simulation of processor's pipeline.:none									*/
	{"PF",		T_PIPEFLUSH},				/*+	Flush the pipeline.:none											*/
	{"POWERSTATS",	T_POWERSTATS},				/*+	Show estimated energy and circuit activity.:none								*/
	{"PS",		T_POWERSTATS},				/*+	Synonym for POWERSTATS.:none											*/
	{"ON",		T_ON},					/*+	Turn the simulator on.:none											*/
	{"OFF",		T_OFF},					/*+	Turn the simulator off.:none											*/
	{"NETDEBUG",	T_NETDEBUG},				/*+	Show debugging information about the simulated network interface.:none						*/
	{"ND",		T_NETDEBUG},				/*+	Synonym for NETDEBUG.:none											*/
	{"LOCSTATS",	T_LOCSTATS},				/*+	Show node's current location in three-dimentional space.:none							*/
	{"LISTRVARS",	T_LISTRVARS},				/*+	List all structures that can be treated as rvars.:none								*/
	{"L",		T_LOCSTATS},				/*+	Synonym for LOCSTATS.:none											*/
	{"SHOWPIPE",	T_SHOWPIPE},				/*+	Show contents of the processor pipeline.:none									*/
	{"N",		T_STEP},				/*+	Step through simulation for a number (default 1) of cycles.:[# cycles] (integer)				*/
	{"LOAD",	T_LOAD},				/*+	Load a script file.:<filename (string)>										*/
	{"SRECL",	T_SRECL},				/*+	Load a binary program in Motorola S-Record format.:none								*/
	{"SETPC",	T_SETPC},				/*+	Set the value of the program counter.:<PC value (integer)>							*/
	{"CONT",	T_CONT},				/*+	Continue execution while PC is not equal to specified PC.:<until PC (hexadecimal)>				*/
	{"HELP",	T_HELP},				/*+	Print list of commands.:none											*/
	{"MAN",		T_MAN},					/*+	Print synopsis for command usage.:<command name>								*/
	{"SHOWCLK",	T_SHOWCLK},				/*+	Show the number of clock cycles simulated since processor reset.:none						*/
	{"NEWNODE",	T_NEWNODE},				/*+	Create a new node (simulated system).:<type=superH|riscv|msp430 (string)> [<x location (real)> <y location (real)> <z location (real)>] [<trajectory file name (string)> <loopsamples (Boolean)> <picoseconds per trajectory sample (integer)>]	*/
	{"SETNODE",	T_SETNODE},				/*+	Set the current simulated node.:<node id (integer)>								*/
	{"PAUINFO",	T_PAUINFO},				/*+	Show information about all valid PAU entries.:none								*/
	{"PI",		T_PAUINFO},				/*+	Synonym for PAUINFO.:none											*/
	{"QUIT",	T_QUIT},				/*+	Exit the simulator.:none											*/
	{"Q",		T_QUIT},				/*+	Synonym for QUIT.:none												*/
	{"SIZEMEM",	T_SIZEMEM},				/*+	Set the size of memory.:<size of memory in bytes (integer)>							*/
	{"DYNINSTR",	T_DYNINSTR},				/*+	Display number of instructions executed.:none									*/
	{"NI",		T_DYNINSTR},				/*+	Synonym for DYNINSTR.:none											*/
	{"SIZEPAU",	T_SIZEPAU},				/*+	Set the size of the PAU.:<size of PAU in number of entries (integer)>						*/
	{"NODETACH",	T_NODETACH},				/*+	Set whether new thread should be spawned on a ON command.:<flag (Boolean)>					*/
	{"CLOCKINTR",	T_CLOCKINTR},				/*+	Toggle enabling clock interrupts.:<flag (Boolean)>								*/
	{"RATIO",	T_RATIO},				/*+	Print ratio of cycles spent active to those spent sleeping.:none						*/
	{"R",		T_RATIO},				/*+	Synonym for RATIO.:none												*/

	{"EBATTINTR",	T_EBATTINTR},				/*+	Toggle enable low battery level interrupts.:<flag (Boolean)>							*/
	{"BATTALERTFRAC",T_BATTALERTFRAC},			/*+	Set battery alert level fraction.:none										*/
	{"NEWBATT",	T_NEWBATT},				/*+	New battery:<ID (integer)> <capacity in mAh (integer)>								*/
	{"BATTNODEATTACH",T_BATTNODEATTACH},			/*+	Attach current node to a specified battery.:<which battery (integer)>						*/
	{"BATTSTATS",	T_BATTSTATS},				/*+	Get battery statistics.:<which battery (integer)>								*/

	{"EFAULTS",	T_EFAULTS},				/*+	Enable interuppt when too many faults occur.:none								*/
	{"FLTTHRESH",	T_FLTTHRESH},				/*+	Set threshold for EFAULTS.:<threshold (integer)>								*/

	{"PFUN",	T_PFUN},				/*+	Change probability distrib fxn (default is uniform).:none							*/
	{"NANOPAUSE",	T_PAUSE},				/*+	Pause the simulation for arg nanoseconds.:<duration of pause in nanoseconds (integer)>				*/
	{"PAUSE",	T_PAUSE},				/*+	Pause the simulation for arg seconds.:<duration of pause in seconds (integer)>					*/

	/*	Interfaces and Networks		*/
	{"NETNEWSEG",		T_NETNEWSEG},			/*+	Add a new network segment to simulation.:<which (if exists) (integer)> <frame bits (integer)> <propagation speed (integer)> <bitrate (integer)> <medium width (integer)> <link failure probability distribution (string)> <link failure distribution mu (real)> <link failure probability distribution sigma (real)> <link failure probability distribution lambda (real)> <link failure duration distribution (string)> <link failure duration distribution mu (real)> <link failure duration distribution sigma (real)> <link failure duration distribution lambda (real)>	*/
	{"NETSEGNICATTACH",	T_NETSEGNICATTACH},		/*+	Attach a current node's IFC to a network segment.:<which IFC (integer)>	<which segment (integer)>													*/
	{"NETCORREL",		T_NETCORREL},			/*+	Specify correlation coefficient between failure of a network segment and failure of an IFC on a node @@NOTE that it is not using the current node so we can specify in a matrix-like form@@.:<which seg (integer)> <which node (integer)> <coefficient (real)>	*/
	{"NETNODENEWIFC",	T_NETNODENEWIFC},		/*+	Add a new IFC to current node frame bits and segno are set at attach time.:<ifc num (if valid) (integer)> <tx pwr (watts) (real)> <rx pwr (watts) (real)> <idle pwr (watts) (real)> <listen pwr (watts) (real)> <fail distribution (string)> <fail distribution mu (real)> <fail distribution sigma (real)> <fail distribution lambda (real)> <transmit FIFO size (integer)> <receive FIFO size (integer)> */
	{"NETSEGDELETE",	T_NETSEGDELETE},		/*+	Disable a specified network segment.:<which segment (integer)>																		*/
	{"NETSEGFAILPROB",	T_NETSEGFAILPROB},		/*+	Set probability of failure for a setseg.:<which segment (integer)> <probability (real)>															*/
	{"NODEFAILPROB",	T_NODEFAILPROB},		/*+	Set probability of failure for current node.:<probability (real)>																	*/
	{"NETSEGFAILDURMAX",	T_NETSEGFAILDURMAX},		/*+	Set maximum network segment failure duration in clock cycles though actual failure duration is determined by probability distribution.:<duration (integer)>						*/
	{"NODEFAILDURMAX",	T_NODEFAILDURMAX},		/*+	Set maximum node failure duration in clock cycles though actual failure duration is determined by probability distribution.:<duration (integer)>							*/
	{"TRACE",		T_TRACE},			/*+	Toggle Tracing.:none																							*/
	{"MALLOCDEBUG",		T_MALLOCDEBUG},			/*+	Display malloc stats.:none																						*/
	{"SETIFCOUI",		T_SETIFCOUI},			/*+	Set OUI for current IFC.:<which IFC (integer)> <new OUI (integer)>																	*/
	{"POWERTOTAL",		T_POWERTOTAL},			/*+	Print total power accross all node.:none																				*/
	{"STOP",		T_STOP},			/*+	Mark the current node as unrunnable.:none																				*/
	{"VERBOSE",		T_VERBOSE},			/*+	Enable the various prints.:none																						*/
	{"V",			T_VERBOSE},			/*+	Synonym for VERBOSE.:none																						*/
	{"DUMPALL",		T_DUMPALL},			/*+	Dump the State structure info for all nodes to the file using given tag and prefix.:<filename (string)> <tag (string)> <prefix (string)>								*/
	{"D",			T_DUMPALL},			/*+	Synonym for DUMPALL.:<filename (string)> <tag (string)> <prefix (string)>																*/
	{"RETRYALG",		T_RETRYALG},			/*+	set NIC retransmission backoff algorithm.:<ifc # (integer)> <algname (string)>																*/
	{"IGN",			T_IGNORENODEDEATHS},		/*+	Ignore node fatalities and continue sim without pausing.:<flag (Boolean)>																*/
	{"SETSCALEALPHA",	T_SETSCALEALPHA},		/*+	Set technology alpha parameter for use in voltage scaling.:<Sakurai alpha (real)>															*/
	{"SETSCALEK",		T_SETSCALEK},			/*+	Set technology K parameter for use in voltage scaling.:<Sakurai K (real)>																*/
	{"SETSCALEVT",		T_SETSCALEVT},			/*+	Set technology Vt for use in voltage scaling.:<Vt (real)>																		*/
	{"SETQUANTUM",		T_SETQUANTUM},			/*+	Set simulation instruction group quantum.:<quantum (integer)>																		*/
	{"SETBASENODEID",	T_SETBASENODEID},		/*+	Set ID of first node from which all node IDs will be offset.:<base (integer)>																*/
	{"RENUMBERNODES",	T_RENUMBERNODES},		/*+	Renumber nodes based on base node ID.:none																				*/
	{"FILE2NETSEG",		T_FILE2NETSEG},			/*+	Connect file to netseg.:<file (string)>	<netseg (integer)>																		*/
	{"NETSEG2FILE",		T_NETSEG2FILE},			/*+	Connect netseg to file.:<netseg (integer)> <file (string)>																		*/
	{"PWD",			T_PWD},				/*+	Get current working directory.:none																					*/
	{"CD",			T_CD},				/*+	Change current working directory.:<path (string)>																			*/
	{"SETTIMERDELAY",	T_SETTIMERDELAY},		/*+	Change granularity of timer intrs.:<granularity in microseconds (integer)>																*/
	{"VERSION",		T_VERSION},			/*+	Display the simulator version and build.:none																				*/
	{"THROTTLE",		T_THROTTLE},			/*+	Set the throttling delay in nanoseconds.:<throttle delay in nanoseconds (integer)>															*/
	{"THROTTLEWIN",		T_THROTTLEWIN},			/*+	Set the throttling window --- main simulation loop sleeps for throttlensecs x throttlewin nanosecs every throttlewin simulation cycles, for an average of throttlensecs sleep per simulation cycle.:<throttle window period in clock cycles (integer)>		*/
	{"RESETNODECTRS",	T_RESETNODECTRS},		/*+	Reset simulation rate measurement trip counters for current node only.:none																*/
	{"RESETALLCTRS",	T_RESETALLCTRS},		/*+	Reset simulation rate measurement trip counters for all nodes.:none																	*/
	{"SIGSRC",		T_SIGNALSRC},			/*+	Create a physical phenomenon signal source.:<type (integer)> <description (string)> <tau (real)> <propagationspeed (real)> <A (real)> <B (real)> <C (real)> <D (real)> <E (real)> <F (real)> <G (real)> <H (real)> <I (real)> <J (real)> <K (real)> <m (real)> <n (real)> <o (real)> <p (real)> <q (real)> <r (real)> <s (real)> <t (real)> <x (real)> <y (real)> <z (real)> <trajectoryfile (string)> <trajectoryrate (real)> <looptrajectory (Boolean)> <samplesfile (string)> <samplerate (integer)> <fixedsampleval (real)> <loopsamples (Boolean)>	*/
	{"SIGSUBSCRIBE",	T_SIGNALSUBSCRIBE},		/*+	Subscribe sensor X on the current node to a signal source Y.:<X (integer)> <Y (integer)>														*/
	{"SENSORSDEBUG",	T_SENSORSDEBUG},		/*+	Display various statistics on sensors and signals.:none 																		*/
	{"SETPHYSICSPERIOD",	T_SETPHYSICSPERIOD},		/*+	Set update periodicity for physical phenomenon simulation.:<period in picoseconds (integer)>														*/
	{"SETBATTFEEDPERIOD",	T_SETBATTFEEDPERIOD},		/*+	Set update periodicity for battery simulation.:<period in picoseconds (integer)>															*/
	{"SETDUMPPWRPERIOD",	T_SETDUMPPWRPERIOD},		/*+	Set periodicity power logging to simlog.:<period in picoseconds (integer)>																*/
	{"FORCEAVGPWR",		T_FORCEAVGPWR},			/*+	Bypass ILPA analysis and set avg pwr consumption.:<avg pwr in Watts (real)> <sleep pwr in Watts (real)>													*/
	{"NETSEGPROPMODEL",	T_NETSEGPROPMODEL},		/*+	Associate a network segment with a signal propagation model.:<netseg ID (integer)> <sigsrc ID (integer)> <minimum SNR (real)>										*/
	{"NUMAREGION",		T_NUMAREGION},			/*+	Specify a memory access latency and a node mapping (can only map into destination RAM) for an address range for a private mapping.:<name string (string)> <start address (inclusive) (hexadecimal)> <end address (non-inclusive) (hexadecimal)> <local read latency in cycles (integer)> <local write latency in cycles (integer)> <remote read latency in cycles (integer)> <remote write latency in cycles (integer)> <Map ID (integer)> <Map offset (integer)> <private flag (Boolean)> */
	{"NUMASTATS",		T_NUMASTATS},			/*+	Display access statistics for all NUMA regions for current node.:none																	*/
	{"NUMASTATSALL",	T_NUMASTATSALL},		/*+	Display access statistics for all NUMA regions for all nodes.:none																	*/
	{"NUMASETMAPID",	T_NUMASETMAPID},		/*+	Change the mapid for nth map table entry on all nodes to i.:<n (integer)> <i (integer)>															*/
	{"DUMPTLB",		T_DUMPTLB},			/*+	Display all TLB entries.:none																						*/
	{"PARSEOBJDUMP",	T_PARSEOBJDUMP},		/*+	Parse a GNU objdump file and load into memory.:<objdump file path (string)>																*/
	{"SPLIT",		T_SPLIT},			/*+	Split current CPU to execute from a new PC and stack.:<newpc (hexadecimal)> <newstackaddr (hexadecimal)> <argaddr (hexadecimal)> <newcpuidstr (integer)>						*/
	{"SFATAL",		T_SFATAL},			/*+	Induce a node death and state dump.:<suicide note (string)>																		*/
	{"SHAREBUS",		T_SHAREBUS},			/*+	Share bus structure with ther named node.:<Bus donor nodeid (integer)>																	*/
	{"ADDVALUETRACE",	T_ADDVALUETRACE},		/*+	Install an address monitor to track data values.:<name string (string)> <base addr (hexadecimal)> <size (integer)> <onstack (Boolean)> <pcstart (hexadecimal)> <frameoffset (integer)>			*/
	{"DELVALUETRACE",	T_DELVALUETRACE},		/*+	Delete an installed address monitor for tracking data values.:<name string (string)> <base addr (hexadecimal)> <size (integer)> <onstack (Boolean)> <pcstart (hexadecimal)> <frameoffset (integer)>	*/
	{"VALUESTATS",		T_VALUESTATS},			/*+	Print data value tracking statistics.:none																				*/
	{"REGISTERSTABS",	T_REGISTERSTABS},		/*+	Register variables in a STABS file with value tracing framework.:<STABS filename (string)>														*/
	{"SETRANDOMSEED",	T_SETRANDOMSEED},		/*+	Reinitialize random number generation system with a specific seed useful in conjunction with GETRANDOMSEED for reproducing same pseudorandom state.:<seed value negative one to use current time (integer)>	*/
	{"GETRANDOMSEED",	T_GETRANDOMSEED},		/*+	Query seed used to initialize random number generation system useful for reinitializing generator to same seed for reproducibility.:none								*/
	{"PCBT",		T_PCBT},			/*+	Dump PC backtrace.:none																							*/
	{"HWSEEREG",		T_HWSEEREG},			/*+	Register a hardware structure or part thereof for inducement of SEEs.: <structure name (string)> <actual bits (integer)> <logical bits (integer)> <bit offset (integer)>				*/
	{"INITSEESTATE",	T_INITSEESTATE},		/*+	Initialize SEE function and parameter state.: <loc pfun (string)> <loc p1 (real)> <loc p2 (real)> <loc p3 (real)> <loc p4 (real)> <bit pfun (string)> <bit p1 (real)> <bit p2 (real)> <bit p3 (real)> <bit p4 (real)> <duration pfun (string)> <dur p1 (real)> <dur p2 (real)> <dur p3 (real)> <dur p4 (real)>		*/
	{"SETMEMRLATENCY",	T_SETMEMRLATENCY},		/*+	Set memory read latency.: <latency in clock cycles (integer)>																		*/
	{"SETMEMWLATENCY",	T_SETMEMWLATENCY},		/*+	Set memory write latency.: <latency in clock cycles (integer)>																		*/
	{"SETFLASHRLATENCY",	T_SETFLASHRLATENCY},		/*+	Set flash read latency.: <latency in clock cycles (integer)>																		*/
	{"SETFLASHWLATENCY",	T_SETFLASHWLATENCY},		/*+	Set flash write latency.: <latency in clock cycles (integer)>																		*/

	


	{"SETNODEMASS",		T_SETNODEMASS},			/*+	Set node mass.: <mass in kg>																						*/
	{"SETPROPULSIONCOEFFS",	T_SETPROPULSIONCOEFFS},		/*+	Set propulsion power model coefficients.: <xk1 xk2 xk3 xk4 xk5 xk6 yk1 yk2 yk3 yk4 yk5 yk6 zk1 zk2 zk3 zk4 zk5 zk6>											*/

	/*										*/
	/*	We should use these and get rid of NETSEGFAILPROB and NODEFAILPROB	*/
	/*										*/
	{"NODEFAILPROBFN", T_NODEFAILPROBFN},			/*+	Specify Node failure Probability Distribution Function (fxn of time).:<expression in terms of constants and 'pow(a,b)' and 't' @@eg '1E-8 + 0.8*pow(2.7182818, t)'@@ (string)>				*/
	{"NETSEGFAILPROBFN", T_NETSEGFAILPROBFN},		/*+	Specify Netseg failure Probability Distribution Function (fxn of time).:<expression in terms of constants and 'pow(a,b)' and 't' @@eg '1E-8 + 0.8*pow(2.7182818, t)'@@ (string)>			*/

	{"BATTILEAK",		T_BATTILEAK},			/*+	Set Battery self-discharge current.:<current in Amperes (real)>																		*/
	{"BATTCF",		T_BATTCF},			/*+	Set Battery Vrate lowpass filter capacitance.:<capacitance in Farads (real)>																*/
	{"BATTINOMINAL",	T_BATTINOMINAL},		/*+	Set Battery Inominal.:<nominal current in Amperes (real)>																		*/
	{"BATTRF",		T_BATTRF},			/*+	Set Battery Vrate lowpass filter resistance.:<resistance in Ohms (real)>																*/
	{"BATTETALUT",		T_BATTETALUT},			/*+	Set Battery etaLUT value.:<LUT index (integer)> <value (real)>																		*/
	{"BATTETALUTNENTRIES",	T_BATTETALUTNENTRIES},		/*+	Set number of etaLUT entries.:<number of entries (integer)>																		*/
	{"BATTVBATTLUT",	T_BATTVBATTLUT},		/*+	Set Battery VbattLUT value.:<index (integer)> <value (real)>																		*/
	{"BATTVBATTLUTNENTRIES",T_BATTVBATTLUTNENTRIES},	/*+	Set number of VbattLUT entries.:<number of entries (integer)>																		*/
	{"BATTVLOSTLUT",	T_BATTVLOSTLUT},		/*+	Set Battery VlostLUT value.:<index (integer)> <value (real)>																		*/
	{"BATTVLOSTLUTNENTRIES",T_BATTVLOSTLUTNENTRIES},	/*+	Set number of VlostLUT entries.:<number of entries (integer)>																		*/
	{"SETBATT",		T_SETBATT},			/*+	Set current battery.:<Battery ID (integer)>																				*/
	{"SETSCHEDRANDOM",	T_SETSCHEDRANDOM},		/*+	Use a different random order for node simulation every cycle.:none																	*/
	{"SETSCHEDROUNDROBIN",	T_SETSCHEDROUNDROBIN},		/*+	Use a round-robin order for node simulation.:none																			*/
	{"SETNETPERIOD",	T_SETNETPERIOD},		/*+	Set period for activting network scheduling.:<period in picoseconds (integer)>																*/
	{"SETFAULTPERIOD",	T_SETFAULTPERIOD},		/*+	Set period for activating fault scheduling.:<period in picoseconds (integer)>																*/
	{"BPT",			T_BPT},				/*+	Set breakpoint.: 'cycles' <ncycles on current node (integer)> | 'instrs' <ninstrs on current node (integer)> | 'sensorreading' <which sensor (integer)> <value (real)> | 'globaltime' <global time in picoseconds (integer)>	*/
	{"BPTLS",		T_BPTLS},			/*+	List breakpoints and their IDs.:none																					*/
	{"BPTDEL",		T_BPTDEL},			/*+	Delete breakpoint.:<breakpoint ID (integer)>																				*/
	{"RANDPRINT",		T_RANDPRINT},			/*+	Print a random value from the selected distribution with given parameters.:<distribution name (string)> <min (real)> <max (real)> <p1 (real)> <p2 (real)> <p3 (real)> <p4 (real)>			*/
	{"SETLOC",		T_SETLOC},			/*+	Set or change node location.:<xloc (real)> <yloc>  (real) <zloc (real)>																	*/
	{"INITRANDTABLE",	T_INITRANDTABLE},		/*+	Set or change node location.:<distname (string)> <pfun name (string)> <basis min (real)> <basis max (real)> <granularity (real)> <p1 (real)> <p2 (real)> <p3 (real)> <p4 (real)>			*/
	{"DEFNDIST",		T_DEFNDIST},			/*+	Define a discrete probability measure as a set of basis value probability tuples.:<list of basis value> (integer list) <list of probabilities>	(real list)						*/
	{"REGISTERRVAR",	T_REGISTERRVAR},		/*+	Register a simulator internal implementation variable or structure for periodic updates either overwriting values or summing determined by the mode parameter.: <sim var name (string)> <index for array structures (integer)> <value dist name (string)> <value dist p1 (real)> <value dist p2 (real)> <value dist p3 (real)> <value dist p4 (real)> <duration dist name (string)> <duration dist p1 (real)> <duration dist p2 (real)> <duration dist p3 (real)> <duration dist p4 (real)> <mode (integer)>	*/



	/*		Breakpoint targets		*/
	{"CYCLES",		T_CYCLES},
	{"INSTRS",		T_INSTRS},
	{"SENSORREADING",	T_SENSORREADING},
	{"GLOBALTIME",		T_GLOBALTIME},

	/*	Assembler Control Instructions		*/
	{".ALIGN",		T_DOTALIGN},
	{".ORG",		T_DOTORG},
	{".GLOBAL",		T_DOTGLOBAL},
	{".TEXT",		T_DOTTEXT},
	{".FILE",		T_DOTFILE},
	{".DATA",		T_DOTDATA},
	{".LONG",		T_DOTLONG},
	{".COMM",		T_DOTCOMM},

	/*	---SuperH---	*/

	/*	SuperH Registers	*/
	{"R0",		T_R0},
	{"R1",		T_R1},
	{"R2",		T_R2},
	{"R3",		T_R3},
	{"R4",		T_R4},
	{"R5",		T_R5},
	{"R6",		T_R6},
	{"R7",		T_R7},
	{"R8",		T_R8},
	{"R9",		T_R9},
	{"R10",		T_R10},
	{"R11",		T_R11},
	{"R12",		T_R12},
	{"R13",		T_R13},
	{"R14",		T_R14},
	{"R15",		T_R15},
	{"GBR",		T_GBR},
	{"VBR",		T_VBR},
	{"MACH",	T_MACH},
	{"MACL",	T_MACL},
	{"PC",		T_PC},
	{"PR",		T_PR},
	{"SPC",		T_SPC},
	{"SR",		T_SR},
	{"SSR",		T_SSR},

	/*	SuperH Instructions	*/
	{"ADD",		T_ADD},
	{"ADDC",	T_ADDC},
	{"ADDV",	T_ADDV},
	{"AND",		T_AND},
	{"ANDB",	T_ANDB},
	{"BF",		T_BF},
	{"BF.S",	T_BFS},
	{"BF/S",	T_BFS},
	{"BRA",		T_BRA},
	{"BRAF",	T_BRAF},
	{"BSR",		T_BSR},
	{"BSRF",	T_BSRF},
	{"BT",		T_BT},
	{"BT.S",	T_BTS},
	{"BT/S",	T_BTS},
	{"CLRMAC",	T_CLRMAC},
	{"CLRS",	T_CLRS},
	{"CLRT",	T_CLRT},
	{"CMP/EQ",	T_CMPEQ},
	{"CMP/GE",	T_CMPGE},
	{"CMP/GT",	T_CMPGT},
	{"CMP/HI",	T_CMPHI},
	{"CMP/HS",	T_CMPHS},
	{"CMP/PL",	T_CMPPL},
	{"CMP/PZ",	T_CMPPZ},
	{"CMP/STR",	T_CMPSTR},
	{"DIV0S",	T_DIV0S},
	{"DIV0U",	T_DIV0U},
	{"DIV1",	T_DIV1},
	{"DMULS.L",	T_DMULSL},
	{"DMULU.L",	T_DMULUL},
	{"DT",		T_DT},
	{"EXTS.B",	T_EXTSB},
	{"EXTS.W",	T_EXTSW},
	{"EXTU.B",	T_EXTUB},
	{"EXTU.W",	T_EXTUW},
	{"JMP",		T_JMP},
	{"JSR",		T_JSR},
	{"LDC",		T_LDC},
	{"LDC.L",	T_LDCL},
	{"LDS",		T_LDS},
	{"LDS.L",	T_LDSL},
	{"LDTLB",	T_LDTLB},
	{"MAC.L",	T_MACL},
	{"MAC.W",	T_MACW},
	{"MOV",		T_MOV},
	{"MOV.B",	T_MOVB},
	{"MOV.L",	T_MOVL},
	{"MOV.W",	T_MOVW},
	{"MOVA",	T_MOVA},
	{"MOVT",	T_MOVT},
	{"MUL.L",	T_MULL},
	{"MULS",	T_MULS},
	{"MULS.W",	T_MULSW},
	{"MULU",	T_MULU},
	{"MULU.W",	T_MULUW},
	{"NEG",		T_NEG},
	{"NEGC",	T_NEGC},
	{"NOP",		T_NOP},
	{"NOT",		T_NOT},
	{"OR",		T_OR},
	{"OR.B",	T_ORB},
	{"PREF",	T_PREF},
	{"RFG",		T_RFG},
	{"ROTCL",	T_ROTCL},
	{"ROTCR",	T_ROTCR},
	{"ROTL",	T_ROTL},
	{"ROTR",	T_ROTR},
	{"RTE",		T_RTE},
	{"RTS",		T_RTS},
	{"SETS",	T_SETS},
	{"SETT",	T_SETT},
	{"SHAD",	T_SHAD},
	{"SHAL",	T_SHAL},
	{"SHAR",	T_SHAR},
	{"SHLD",	T_SHLD},
	{"SHLL",	T_SHLL},
	{"SHLL2",	T_SHLL2},
	{"SHLL8",	T_SHLL8},
	{"SHLL16",	T_SHLL16},
	{"SHLR",	T_SHLR},
	{"SHLR2",	T_SHLR2},
	{"SHLR8",	T_SHLR8},
	{"SHLR16",	T_SHLR16},
	{"SLEEP",	T_SLEEP},
	{"STC",		T_STC},
	{"STC.L",	T_STCL},
	{"STS",		T_STS},
	{"STS.L",	T_STSL},
	{"SUB",		T_SUB},
	{"SUBC",	T_SUBC},
	{"SUBV",	T_SUBV},
	{"SWAP.B",	T_SWAPB},
	{"SWAP.W",	T_SWAPW},
	{"TAS.B",	T_TASB},
	{"TRAPA",	T_TRAPA},
	{"TST",		T_TST},
	{"TSTB",	T_TSTB},
	{"XOR",		T_XOR},
	{"XOR.B",	T_XORB},
	{"XTRCT",	T_XTRCT},

	{0,		0},
};

int
yylex(void)
{
	/*									*/
	/* 	It is the responsibility of the main driver program/fxn to	*/
	/*	initialize istream data structure, thus we do not depend on	*/
	/*	what the type of input stream is.				*/
	/*									*/
	int	i;
	char	*tmpdata;
	char	*bptr;
	Datum	*tllp = yyengine->labellist.tail;
	Datum	*tmphd;
	char	*aptr ;
	int	chunklen;


	if ((yyengine->istream.head == NULL) || (yyengine->istream.head->data == NULL))
	{
		/* EOF */
		//clearistream();
		return (0);
	}

	aptr = yyengine->istream.head->data;
	chunklen = strlen(yyengine->istream.head->data);


	/*	Used to hold a copy of token as we conv to uppercase.		*/
	tmpdata = (char *) mmalloc(yyengine, (chunklen+1)*sizeof(char), "tmpdata in lex.inc");
	if (tmpdata == NULL)
	{
		mprint(yyengine, NULL, siminfo,
			"Could not allocate memory for char *tmpdata in yylex(), main.c");
		mexit(yyengine, "See above messages.", -1);
	}

	bptr = tmpdata;
	for (i = 0; i < chunklen; i++)
	{
		*bptr++ = toupper(*aptr++);
	}
	*bptr++ = '\0';


	/*									*/
	/*	If we see '--', a comment has begun. Throw everything until,	*/
	/*	and including, the next '\n', away. Even if scanning, delete	*/
	/*	from the istream.						*/
	/*									*/
	if ((yyengine->istream.head->data[0] == '-') &&
		(yyengine->istream.head->prev != NULL) &&
		(((Datum *)yyengine->istream.head->prev)->data != NULL) &&
		(((Datum *)yyengine->istream.head->prev)->data[0] == '-'))
	{
		while ((yyengine->istream.head != NULL) && strcmp(yyengine->istream.head->data, "\n"))
		{
			tmphd = yyengine->istream.head;
			yyengine->istream.head = yyengine->istream.head->prev;

			if (!yyengine->scanning)
			{
				yyengine->istream.head->next = NULL;
				mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
				mfree(yyengine, tmphd, "tmphd in lex.c");
			}
		}
			
		/*	This was allocated just for uppercase stuff. Free it	*/
		mfree(yyengine, tmpdata, "tmpdata in lex.c");

		return	T_COMMENT;
	}

	/*									*/
	/*				Label definition:			*/
	/* 	If we are in the SCANNING phase, we got here after we had built	*/
	/*	the labellist, but had not yet assigned correct displacements	*/
	/*	to T_LABELS. In that case, search labellist and set the disp 	*/
	/*	to the current yyengine->cp->PC. So, check if it is a label...		*/
	/*									*/
	if (tmpdata[strlen(tmpdata)-1] == ':')
	{
		if (yyengine->scanning)
		{
			while (tllp != NULL)
			{
				if (!strncmp(tllp->data,\
					yyengine->istream.head->data,\
					strlen(yyengine->istream.head->data)-1)) /* -1 for the ':' */
				{
					/* 	Set correct value of displacement.	*/
					tllp->value = yyengine->cp->PC;

					/*	We move head, but dont really unlink	*/
					yyengine->istream.head = yyengine->istream.head->prev;
						
					/*	Alloc'd for uppercase stuff. Free it	*/
					mfree(yyengine, tmpdata, "tmpdata in lex.c");

					return	T_LABELDEFN;
				}
				tllp = tllp->next;
			}

			mprint(yyengine, NULL, siminfo, "Saw a T_LABELDEFN that was missed by scan_labels!!");
			mexit(yyengine, "See above messages.", -1);
		}

		/*	Not scanning, so we must unlink it from token list	*/
		tmphd = yyengine->istream.head;
		yyengine->istream.head = yyengine->istream.head->prev;
		yyengine->istream.head->next = NULL;
		mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
		mfree(yyengine, tmphd, "tmphd in lex.c");

		/*	This was allocated just for uppercase stuff. Free it	*/
		mfree(yyengine, tmpdata, "tmpdata in lex.c");

		return	T_LABELDEFN;
	}

	/*									*/
	/*				Global var defn:			*/
	/*	Recognise it, and set values in labellist, but don't touch 	*/
	/*	anything else, let yylex return tokens to match ".comm" expr	*/
	/*									*/
	if (!strcmp(tmpdata, ".COMM"))
	{
		if (yyengine->scanning)
		{
			while (tllp != NULL)
			{
				if (!strcmp(tllp->data, ((Datum *)yyengine->istream.head->prev)->data))
				{
					/* 	Set correct value of displacement	*/
					tllp->value = yyengine->cp->PC;
					break;
				}
				tllp = tllp->next;
			}

			if (tllp == NULL)
			{
				mprint(yyengine, NULL, siminfo,
					"Saw a name missed by scan_labels_and_globalvars!");
				mexit(yyengine, "See above messages.", -1);
			}
		}
	}

	/*									*/
	/*				Label use ? :				*/
	/*	All labels are detected, and the labellist built in SCANNING 	*/
	/*	pass, that is performed before _real_ parsing phase. If in	*/
	/*	the SCANNING pass, the yylval.val returned is obviously junk,	*/
	/*	and we should not free list on input stream list.		*/
	/*									*/
	while (tllp != NULL)
	{
		if (!strcmp(tllp->data, yyengine->istream.head->data))
		{
			/* 	Set yylval to addr(label)	*/
			yylval.uval = tllp->value;

			/* 	Keep labellist, remove token from input list	*/
			tmphd = yyengine->istream.head;
			yyengine->istream.head = yyengine->istream.head->prev;

			if (!yyengine->scanning)
			{
				yyengine->istream.head->next = NULL;
				mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
				mfree(yyengine, tmphd, "tmphd in lex.c");
			}

			/*	Allocated just for uppercase stuff. Free it	*/
			mfree(yyengine, tmpdata, "tmpdata in lex.c");

			return T_LABEL;
		}
		tllp = tllp->next;
	}

	/*	The way we handle HELP is kinda a hack, but what the heck	*/
	if (!strcmp(tmpdata, "MAN"))
	{
		Datum	*tmphd;
	

		if ((yyengine->istream.head->prev != NULL) &&
			(((Datum *)yyengine->istream.head->prev)->data[0] == '\n'))
		{
			/*	A lone 'MAN' is treated as a 'HELP'	*/
			tmphd = yyengine->istream.head;
			yyengine->istream.head = yyengine->istream.head->prev;

			if (!yyengine->scanning)
			{
				yyengine->istream.head->next = NULL;
				mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
				mfree(yyengine, tmphd, "tmphd in lex.c");
			}

			/*	This was allocated just for uppercase stuff. Free it	*/
			mfree(yyengine, tmpdata, "tmpdata in lex.c");

			return T_HELP;
		}

		yylval.str = (char *) mrealloc(yyengine, yylval.str, 
					MAX_BUFLEN*sizeof(char), 
					"yylval.str (MAN) in lex.inc");

		aptr = ((Datum *)yyengine->istream.head->prev)->data;
		bptr = yylval.str;
		while (*aptr != '\0')
		{
			*bptr++ = toupper(*aptr++);
		}
		*bptr++ = '\0';

		/*	Twice, past MAN command and subsequent token	*/
		tmphd = yyengine->istream.head;
		yyengine->istream.head = yyengine->istream.head->prev;

		if (!yyengine->scanning)
		{
			yyengine->istream.head->next = NULL;
			mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
			mfree(yyengine, tmphd, "tmphd in lex.c");
		}

		tmphd = yyengine->istream.head;
		yyengine->istream.head = yyengine->istream.head->prev;
		
//		if (!yyengine->scanning)
//		{
//			yyengine->istream.head->next = NULL;
//			mfree(yyengine, tmphd->data);
//			mfree(yyengine, tmphd);
//		}

		/*	This was allocated just for uppercase stuff. Free it	*/
		mfree(yyengine, tmpdata, "tmpdata in lex.c");

		return T_MAN;
	}

	/* 	check if it is a token 		*/
	for (i = 0; superH_token_table[i].token != 0; i++)
	{
			/*	Generic match found:	*/
			if (!strcmp(tmpdata, superH_token_table[i].token))
			{
				/* we do not set yylval : token has no "value" */
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}

				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return superH_token_table[i].token_value;
			}

			if (!strncmp(tmpdata, "#", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}
				
				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return '#';
			}

			if (!strncmp(tmpdata, ",", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}
				
				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return ',';
			}
			
			if (!strncmp(tmpdata, ")", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}

				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return ')';
			}	
		
			if (!strncmp(tmpdata, "(", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}

				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return '(';
			}			

			if (!strncmp(tmpdata, "@", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}

				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return '@';
			}

			if (!strncmp(tmpdata, "-", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}

				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return '-';
			}			

			if (!strncmp(tmpdata, "+", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}

				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return '+';
			}

			if (!strncmp(tmpdata, "!", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}

				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return '!';
			}

			if (!strncmp(tmpdata, "\n", 1))
			{
				tmphd = yyengine->istream.head;
				yyengine->istream.head = yyengine->istream.head->prev;
				if (!yyengine->scanning)
				{
					if (yyengine->istream.head != NULL) yyengine->istream.head->next = NULL;
					mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
					mfree(yyengine, tmphd, "tmphd in lex.c");
				}

				/*	This was allocated just for uppercase stuff. Free it	*/
				mfree(yyengine, tmpdata, "tmpdata in lex.c");

				return '\n';
			}
	}

	/*								*/
	/* 	Match not found for this token, return T_STRING, 	*/
	/*	use un-uppercased data.					*/
	/*								*/
	yylval.str = (char *) mmalloc(yyengine, (strlen(tmpdata)+1)*sizeof(char),
					"yylval.str in lex.inc");
	if (yylval.str == NULL)
	{
		mprint(yyengine, NULL, siminfo,
			"Failed to allocate memory in lex.c. Sorry. Exiting...\n\n");
		mexit(yyengine, "See above messages.", -1);
	}

	strncpy(yylval.str, yyengine->istream.head->data, strlen(yyengine->istream.head->data)+1); 

	/* 	move it off input queue		*/
	tmphd = yyengine->istream.head;
	yyengine->istream.head = yyengine->istream.head->prev;
	if (!yyengine->scanning)
	{
		yyengine->istream.head->next = NULL;
		mfree(yyengine, tmphd->data, "tmphd->data in lex.c");
		mfree(yyengine, tmphd, "tmphd in lex.c");
	}

	/*	This was allocated just for uppercase stuff. Free it	*/
	mfree(yyengine, tmpdata, "tmpdata in lex.c");


	return T_STRING;
}
