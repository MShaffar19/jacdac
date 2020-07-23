# Logger

    identifier: 0x12dc1fca

A service which can report messages to the bus.

## Registers

    enum Priority : u8 {
        Debug = 0,
        Log = 1,
        Warning = 2,
        Error = 3
    }
    rw min_priority = 1: Priority @ 0x80

Messages with level lower than this won't be emitted. The default setting may vary.

## Commands

    report debug @ 0x80 {
        message: string
    }
    report log @ 0x81 {
        message: string
    }
    report warn @ 0x82 {
        message: string
    }
    report error @ 0x83 {
        message: string
    }

Report a message.