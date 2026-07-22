### cpp api developemnt

Pure C++ sockets → maximum learning, maximum pain
cpp-httplib → easiest C++ option, just one header file
Crow → closest to Flask feeling in C++
Drogon → if you want serious production C++ API
For most use cases Python is still the better choice — use C++ when performance truly matters

---

### Install and run ngrok

### Install ngrok via Apt with the following command:

```bash
# install ngrok
curl -sSL https://ngrok-agent.s3.amazonaws.com/ngrok.asc \
  | sudo tee /etc/apt/trusted.gpg.d/ngrok.asc >/dev/null \
  && echo "deb https://ngrok-agent.s3.amazonaws.com bookworm main" \
  | sudo tee /etc/apt/sources.list.d/ngrok.list \
  && sudo apt update \
  && sudo apt install ngrok

# sign up free at ngrok.com, then authenticate from ngrok website

ngrok config add-authtoken $YOUR_AUTHTOKEN

# expose your local server, Get a public URL for your app

ngrok http 8000

# Open your dev domain in a browser to see it working!
# Your dev domain: https://darkening-jurist-straining.ngrok-free.dev
```
