# Logs

A logging util that is just a .h file.

Logs are stored in a separate logs/ folder, created on init.


Logs are named based on run time where l_init() was called.


To start, copy log.h into your project and put ```LOG_INIT``` at the top along with the #includes.

Then, put init at the top of main.
```c
l_init();
```

And remember to close it too at the end.
```c
l_close();
```

l_log logs to stdout/stderr AND a file in ```./logs/```
```c
l_log(L_INFO, "Hello");
```

Depending on the flag (L_INFO, L_ERR), l_log will also print to stdout or stderr

l_flog logs a formatted string
```c
l_flog(L_ERR, "What's %i + %i?", 9, 10);
```

For logging to file only:
```c
l_flog(flag, msg);
l_flogf(flag, msg, ...);
```

For logging to stdout only:
```c
l_olog(flag, msg);
l_ologf(flag, msg, ...);
```

For logging to stderr only:
```c
l_elog(flag, msg);
l_elogf(flag, msg, ...);
```

Currently supported log types and their flags:
- Info -```INFO```
- Error - ```ERR```

See main.c for examples. 
