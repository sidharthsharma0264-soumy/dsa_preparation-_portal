from flask import Flask, render_template

app = Flask(__name__)


@app.route("/")
def home():
    return render_template("index.html")


@app.route("/login")
def login():
    return render_template("login.html")


@app.route("/register")
def register():
    return render_template("register.html")


@app.route("/dashboard")
def dashboard():
    return render_template("dashboard.html")


@app.route("/topics")
def topics():
    return render_template("topics.html")


@app.route("/notes")
def notes():
    return render_template("notes.html")


@app.route("/array-notes")
def array_notes():
    return render_template("array_notes.html")


@app.route("/string-notes")
def string_notes():
    return render_template("string_notes.html")


@app.route("/linked-list-notes")
def linked_list_notes():
    return render_template("linked_list_notes.html")


@app.route("/stack-notes")
def stack_notes():
    return render_template("stack_notes.html")


@app.route("/queue-notes")
def queue_notes():
    return render_template("queue_notes.html")


@app.route("/tree-notes")
def tree_notes():
    return render_template("tree_notes.html")


@app.route("/graph-notes")
def graph_notes():
    return render_template("graph_notes.html")


@app.route("/dp-notes")
def dp_notes():
    return render_template("dp_notes.html")


@app.route("/videos")
def videos():
    return render_template("videos.html")


@app.route("/progress")
def progress():
    return render_template("progress.html")


@app.route("/about")
def about():
    return render_template("about.html")


if __name__ == "__main__":
    app.run(debug=True)