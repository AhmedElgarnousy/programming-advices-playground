from flask import Flask, request, jsonify

app = Flask(__name__)


def sum (a, b):
    return a +b

@app.route('/sum', methods=['GET'])
def sum_endpoint():
    a = int(request.args.get('a'))
    b = int(request.args.get('b'))
    result = sum(a, b)
    return jsonify({"result": result})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)


# http://127.0.0.1:8000/sum?a=3&b=5