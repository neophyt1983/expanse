# expanse is the working title for a social media platform for the people.

I, Dale, believe that people want social media as evidenced by the success of many platforms but because of the small monopoly <Facebook>
people cannot have the security they deserve. The goal of expanse is to alleviate this by first hosting the open source software locally, on your device, which allows you to control where your information goes. Second expanse is not data mining you, Ever!

This project is in its infancy and growing slowly at the moment. I welcome suggestions and more than that I invite you to join the team developing this software. Please engage us here at
<b>https://riot.im/app/#/room/#expanse:matrix.org</b> view your desktop web browser or the <b>#expanse:matrix.org</b> if you already have the Riot.im application on your platform of choice.

Important things to note about this project:

      - The nCurses version is foundational and everything, except graphics, that works in it must work on all other versions and
        vis-versa. This means menu options that point to a function in the Windows version or the Android version, again assuming
        they aren't for some graphical reason, will work and be available in the nCurses version. Objects that are created by users
        and things that exist in the program by default must also exist in the nCurses version in a similar fashion to their
        graphical counterpart.
        *Obviously there are things that are either challenging or impossible when going between a GUI ann CLI the important part
         that the spirit of functions and objects is maintained when developing to ensure a near seamless transition between the
         different environments.
       - Objects will be identified by a UUID to ensure that the objects can exist in multiple versions of the expanse and in both
         supported environments. This UUID will be connected to all iterations of the object and erased when the object dies.
       - Encryption is supper important! End to end for users encryption of communications and file encryption for users personal
         data.
       - The network topology is to be decentralized with each person connecting to others via other users via best route
         determined by latency, reported network load, and device workload.
         *Just a thought but we could build the town map based on latency but I'm interested if there is a better idea.
       - Minimize the amount of traffic by sharing via peer-to-peer for objects that are not protected.
       - CPU's with multiple will be supported to cut back on local workload also because it's 2017 and this should be a thing.
       - DOCUMENT! Please for the sake of everyone document your changes to the best of your ability. There should be folks looking
         over the code and documents to ensure that there grammer is good and the comments, etc are readable but don't leave them
         a mess.
       - Not done yet...
