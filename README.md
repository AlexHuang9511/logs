# Logs

A logging util that is just a .h file.

Logs are stored in a separate logs/ folder, created on init.


Logs are named based on run time where l_init() was called.


To start, copy log.h into your project and put init at the top of main.
```c
l_init();
```

And remember to close it too.
```c
l_close();
```

Use l_log to log a string.
```c
l_log(INFO, "Hello");
```

Use l_flog to log a formatted string.
```c
l_flog(ERR, "What's %i + %i?", 9, 10);
```

Currently supported log types and their flags:
- Info -```INFO```
- Error - ```ERR```


See main.c for examples. 
