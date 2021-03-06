// Autogenerated C header file for Azure IoT Hub
#ifndef _JACDAC_SPEC_IOT_HUB_H
#define _JACDAC_SPEC_IOT_HUB_H 1

#define JD_SERVICE_CLASS_IOT_HUB  0x19ed364c

/**
 * No args. Try connecting using currently set `connection_string`.
 * The service normally preiodically tries to connect automatically.
 */
#define JD_IOT_HUB_CMD_CONNECT 0x80

/**
 * No args. Disconnect from current Hub if any.
 * This disables auto-connect behavior, until a `connect` command is issued.
 */
#define JD_IOT_HUB_CMD_DISCONNECT 0x81

/**
 * Sends a short message in string format (it's typically JSON-encoded). Multiple properties can be attached.
 */
#define JD_IOT_HUB_CMD_SEND_STRING_MSG 0x82
typedef struct jd_iot_hub_send_string_msg {
    char msg[0];  // string0
    // char property_name[0];  // string0
    // char property_value[0];  // string0
} jd_iot_hub_send_string_msg_t;


/**
 * Report: No args
 */

/**
 * No args. Sends an arbitrary, possibly binary, message. The size is only limited by RAM on the module.
 */
#define JD_IOT_HUB_CMD_SEND_MSG_EXT 0x83

/**
 * Report: Argument: message pipe_port (uint16_t)
 */

/**
 * Argument: body bytes. Part of the body of the message.
 */

/**
 * Set properties on the message. Can be repeated multiple times.
 */
#define JD_IOT_HUB_PIPE_PROPERTIES 0x1
typedef struct jd_iot_hub_properties {
    uint32_t identifier; // 0x1
    char property_name[0];  // string0
    // char property_value[0];  // string0
} jd_iot_hub_properties_t;


/**
 * Argument: devicebound pipe (bytes). Subscribes for cloud to device messages, which will be sent over the specified pipe.
 */
#define JD_IOT_HUB_CMD_SUBSCRIBE 0x84

/**
 * If there are any properties, this meta-report is send one or more times.
 * All properties of a given message are always sent before the body.
 */
#define JD_IOT_HUB_PIPE_DEVICEBOUND_PROPERTIES 0x1
typedef struct jd_iot_hub_devicebound_properties {
    uint32_t identifier; // 0x1
    char property_name[0];  // string0
    // char property_value[0];  // string0
} jd_iot_hub_devicebound_properties_t;


/**
 * Argument: body bytes. For every message, the body is sent in one or more reports like this.
 */

/**
 * Argument: twin_result pipe (bytes). Ask for current device digital twin.
 */
#define JD_IOT_HUB_CMD_GET_TWIN 0x85

/**
 * Argument: json bytes. The JSON-encoded twin. This is typically something like:
 * `{ "desired": { "foo": 1, "$version": 12 }, "reported": { "foo": 1, "bar" 2, "$version": 123 } }`
 */

/**
 * Argument: status_code uint32_t. This emitted if status is not 200.
 */
#define JD_IOT_HUB_PIPE_TWIN_ERROR 0x1
typedef struct jd_iot_hub_twin_error {
    uint32_t identifier; // 0x1
    uint32_t status_code;
} jd_iot_hub_twin_error_t;


/**
 * Argument: twin_updates pipe (bytes). Subscribe to updates to our twin.
 */
#define JD_IOT_HUB_CMD_SUBSCRIBE_TWIN 0x87

/**
 * Argument: json bytes. First, the current value of the twin is sent (this includes desired and reported properties).
 * Next updates done by the back-end are streamed as they arrive (they only include the desired properties).
 */

/**
 * No args. Start twin update.
 */
#define JD_IOT_HUB_CMD_PATCH_TWIN 0x86

/**
 * Report: Argument: patch_port pipe_port (uint16_t)
 */

/**
 * Argument: json bytes. The JSON-encoded twin update. The pipe should be closed when the last packet is sent.
 * You just send updates for `reported` field, like this:
 * `{ "bar": 3, "baz": null }` (skip `"$version"` and no `"reported": { ... }`).
 */

/**
 * Argument: method_call pipe (bytes). Subscribe to direct method calls.
 */
#define JD_IOT_HUB_CMD_SUBSCRIBE_METHOD 0x88

/**
 * Argument: json bytes. The method call body is sent using these packets.
 * If the body is empty, a single empty `method_call_body` is sent.
 */

/**
 * This is sent after the last part of the `method_call_body`.
 */
#define JD_IOT_HUB_PIPE_METHOD_CALL 0x1
typedef struct jd_iot_hub_method_call {
    uint32_t identifier; // 0x1
    char method_name[0];  // string0
    // char request_id[0];  // string0
} jd_iot_hub_method_call_t;


/**
 * Respond to a direct method call (`request_id` comes from `subscribe_method` pipe).
 */
#define JD_IOT_HUB_CMD_RESPOND_TO_METHOD 0x89
typedef struct jd_iot_hub_respond_to_method {
    uint32_t status;
    char request_id[0];  // string0
} jd_iot_hub_respond_to_method_t;


/**
 * Report: Argument: response_body pipe_port (uint16_t)
 */

/**
 * Argument: json bytes. The pipe should be closed when the last packet of response body is sent.
 */

/**
 * Read-only string (bytes). Returns `"ok"` when connected, and an error description otherwise.
 */
#define JD_IOT_HUB_REG_CONNECTION_STATUS 0x180

/**
 * Read-write string (bytes). Connection string typically looks something like 
 * `HostName=my-iot-hub.azure-devices.net;DeviceId=my-dev-007;SharedAccessKey=xyz+base64key`.
 * You can get it in `Shared access policies -> iothubowner -> Connection string-primary key` in the Azure Portal.
 * This register is write-only.
 * You can use `hub_name` and `device_id` to check if connection string is set, but you cannot get the shared access key.
 */
#define JD_IOT_HUB_REG_CONNECTION_STRING 0x80

/**
 * Read-only string (bytes). Something like `my-iot-hub.azure-devices.net`; empty string when `connection_string` is not set.
 */
#define JD_IOT_HUB_REG_HUB_NAME 0x181

/**
 * Read-only string (bytes). Something like `my-dev-007`; empty string when `connection_string` is not set.
 */
#define JD_IOT_HUB_REG_DEVICE_ID 0x182

/**
 * Emitted upon successful connection.
 */
#define JD_IOT_HUB_EV_CONNECTED 0x80

/**
 * Argument: reason string (bytes). Emitted when connection was lost.
 */
#define JD_IOT_HUB_EV_CONNECTION_ERROR 0x81

/**
 * This event is emitted upon reception of a cloud to device message, that is a string
 * (doesn't contain NUL bytes) and fits in a single event packet.
 * For reliable reception, use the `subscribe` command above.
 */
#define JD_IOT_HUB_EV_DEVICEBOUND_STR 0x82
typedef struct jd_iot_hub_devicebound_str {
    char msg[0];  // string0
    // char property_name[0];  // string0
    // char property_value[0];  // string0
} jd_iot_hub_devicebound_str_t;


#endif
