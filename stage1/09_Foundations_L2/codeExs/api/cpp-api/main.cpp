#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Parse query string like "a=3&b=5" into a map
std::map<std::string, std::string> parse_query(const std::string &query)
{
    std::map<std::string, std::string> params;
    std::stringstream ss(query);
    std::string pair;

    while (std::getline(ss, pair, '&'))
    {
        size_t eq = pair.find('=');
        if (eq != std::string::npos)
        {
            std::string key = pair.substr(0, eq);
            std::string val = pair.substr(eq + 1);
            params[key] = val;
        }
    }
    return params;
}

// Parse the first line of HTTP request like "GET /sum?a=3&b=5 HTTP/1.1"
void parse_request(const std::string &raw, std::string &path, std::map<std::string, std::string> &params)
{
    std::stringstream ss(raw);
    std::string method, full_path;
    ss >> method >> full_path;

    size_t q = full_path.find('?');
    if (q != std::string::npos)
    {
        path = full_path.substr(0, q);
        params = parse_query(full_path.substr(q + 1));
    }
    else
    {
        path = full_path;
    }
}

// Build HTTP response
std::string make_response(int status, const std::string &body)
{
    std::string status_text = (status == 200) ? "OK" : "Not Found";
    return "HTTP/1.1 " + std::to_string(status) + " " + status_text + "\r\n"
                                                                      "Content-Type: application/json\r\n"
                                                                      "Content-Length: " +
           std::to_string(body.size()) + "\r\n"
                                         "\r\n" +
           body;
}

// Your actual logic
int sum(int a, int b)
{
    return a + b;
}

int main()
{
    // 1. Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Allow port reuse so we can restart quickly
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 2. Bind to address and port
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8000);
    bind(server_fd, (sockaddr *)&address, sizeof(address));

    // 3. Listen for connections
    listen(server_fd, 10);
    std::cout << "Running on http://0.0.0.0:8000\n";

    // 4. Accept and handle requests forever
    while (true)
    {
        int client_fd = accept(server_fd, nullptr, nullptr);

        // Read the HTTP request
        char buffer[4096] = {};
        read(client_fd, buffer, sizeof(buffer));

        // Parse path and query params
        std::string path;
        std::map<std::string, std::string> params;
        parse_request(std::string(buffer), path, params);

        std::cout << "Request: " << path << "\n";

        // Route the request
        std::string response;

        if (path == "/")
        {
            response = make_response(200, "{\"message\": \"Hello world from cpp API by ahmed kamal\"}");
        }
        else if (path == "/sum")
        {
            int a = params.count("a") ? std::stoi(params["a"]) : 0;
            int b = params.count("b") ? std::stoi(params["b"]) : 0;
            int result = sum(a, b);
            response = make_response(200, "{\"result\": " + std::to_string(result) + "}");
        }
        else
        {
            response = make_response(404, "{\"error\": \"Not found\"}");
        }

        // Send response and close connection
        write(client_fd, response.c_str(), response.size());
        close(client_fd);
    }

    close(server_fd);
    return 0;
}