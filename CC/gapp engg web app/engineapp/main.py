import webapp2
import os
import jinja2

class defaultHandler(webapp2.RequestHandler):
    def get(self):
        self.response.write('Hello World!')

template_dir = os.path.join(os.path.dirname(__file__), 'templates')
jinja_env = jinja2.Environment(loader=jinja2.FileSystemLoader(template_dir), autoescape=True)

class Page1Handler(webapp2.RequestHandler):
    def get(self):
        template = jinja_env.get_template('page1.html')
        self.response.write(template.render())

class Page2Handler(webapp2.RequestHandler):
    def get(self):
        template = jinja_env.get_template('page2.html')
        self.response.write(template.render())

app = webapp2.WSGIApplication([
    ('/', defaultHandler),
    ('/page1', Page1Handler),
    ('/page2', Page2Handler)
], debug=True)

