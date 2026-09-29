#include <iostream>
#include "greenapi.hpp"

/*
 * Example of sending a WhatsApp message using GREEN-API
 * Documentation: https://green-api.com/en/docs/api/sending/SendMessage/
 */
int main()
{
    // 1. Replace the placeholders with your actual Instance ID and Token from console.green-api.com
    std::string idInstance = "710722692479";
    std::string apiTokenInstance = "b5bf54716c3d43848289cf3d554a139e60b2b81c1248402694";

    greenapi::GreenApi instance{
        "https://api.green-api.com",
        "https://media.green-api.com",
        idInstance,
        apiTokenInstance};

    // 2. Replace the target number. Use the full international format without '+' or spaces.
    // For a personal chat, append "@c.us". For a group chat, append "@g.us".
    std::string recipientChatId = "201551442559@c.us"; // Example for Egypt: Country code 20 + number

    nlohmann::json sendMessageJson{
        {"chatId", recipientChatId},
        {"message", "Hello! I am sending this WhatsApp message using C++ and the GREEN-API SDK."}};

    // 3. Execute the API request
    std::cout << "Sending message..." << std::endl;
    greenapi::Response sendMessage = instance.sending.sendMessage(sendMessageJson);

    // 4. Handle the response
    if (sendMessage.error)
    {
        std::cerr << "Error sending message!" << std::endl;
        std::cerr << "Status Code: " << sendMessage.status_code << std::endl;
        std::cerr << "Response Body: " << sendMessage.bodyStr << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Success! Message sent successfully." << std::endl;
        std::cout << "Message ID: " << sendMessage.bodyJson["idMessage"] << std::endl;
    }

    return 0;
}
