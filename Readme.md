This repo takes the Air Manager Overhead instruments for the PMDG 737 700 created originally by Detlef von Reusner, and has the converted lua code to work with the iFly 737 Max 8...

**UPDATES**
- Some controls do not "trigger" the appropriate actions, particularly things like apu start, etc... it seems there are "double-click" like activities or some other trigger happening in the plane itself... will need further investigation. However, still useful for things like lights
***********


I've included all of the code that was used, including:

-iflymax8lvars-vcs.txt :  this is a list of the lvars from the MAX8 gathered using FSUIPC 7 ( Addons->WASM->List LVars)

All of the original lua script remains intact as comments in each file

All of the conversion work was done using GitHub Copilot in Agent Mode... I've included my complete chat history as an export (see chat.json) if  you're interested in seeing how things went step by step, but otherwise, i kicked off the agent interaction with the following prompt:

"In this workspace, there's a file called iflymax8lvars-vcs.txt... this contains a list of all the simulation variables for the iflymax8... In the resources folder, there are a number of instruments, each in its own folder. the logic is in a file called logic.lua...these intruments are for a different vendor's airplane, and I need to convert them to the ifly737max... to call events against a particular control in the ifly, we use a fs2020 _variable_write, or msfs_variable_write command, instead of using an event command... in general, the ifly uses variable values from 0 and up, in increments of 10, so 0,10,20, etc... while the instruments will generally use 0 and 1 for simply 2 position switches, and 1,2,3 for three position switches.
Let's go through each instrument one at a time, together, and interactively upgrade them. guide me through the process... we'll look at each control in sequence... always verify with me your decisions (for example, what sim variable) and ask me if you don't know. never change existing code, always create a commented out copy of the existing code block before you change anything."


You can see the ifly_conversion_process.md in the repo that copilot agent used to track it's work as it went.

The entire process for all of the overhead instruments took just under an hour...while it made a couple of mistakes along the way, it fixed them when I pointed out the issues.

I've also included an export of all of the instruments in a ifly737max8oh.siff file in this repo...

None of this is absolutely perfect, but feel free to take this further if you'd like. I did this as an experiment for my own use, and thought I'd share.
