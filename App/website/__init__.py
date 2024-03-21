from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from .event import socketIO
from .views import views

db = SQLAlchemy()
DB_NAME = "database.db"


def create_app():
    app = Flask(__name__)
    # app.config['SECRET_KEY'] = 'hafnaksfnaskf assa'
    # app.config['SQLALCHEMY_DATABASE_URI'] = f'sqlite:///{DB_NAME}'
    # db.init_app(app)

    

    app.register_blueprint(views, url_prefix = '/')
    socketIO.init_app(app)

    return app
