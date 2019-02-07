#include "PageTemplate.h"

String PageTemplate::PageBegin()
{
    return "<!DOCTYPE html>"
           "<html>"
           "  <head>"
           "    <meta charset=\"utf-8\">"
           "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"
           "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">"
           "    <title>" +
           Title + "</title>"
                   "    <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.5/css/bootstrap.min.css\" crossorigin=\"anonymous\">"
                   "    <style>"
                   "      .footer,body{padding-top:1.0rem}.header,.jumbotron{border-bottom:.05rem solid #e5e5e5}body{padding-bottom:1.5rem}.lead{padding-top:1rem; padding-bottom:1.5rem}"
                   "      .footer,.header{padding-right:1rem;padding-left:1rem}.header{padding-bottom:1rem}.header h3{margin-top:0;margin-bottom:0;line-height:3rem}"
                   "      .footer{color:#777;border-top:.05rem solid #e5e5e5}@media (min-width:48em){.container{max-width:46rem}}.container-narrow>hr{margin:2rem 0}"
                   "      .jumbotron{text-align:center}.jumbotron .btn{padding:.75rem;font-size:1.5rem; margin:5px;width:200px}@media screen and (min-width:48em){.footer,"
                   "      .header{padding-right:0;padding-left:0}.header{margin-bottom:2rem}.jumbotron{border-bottom:0}}p{margin:0px}"
                   "    </style>"
                   "  </head>"
                   "  <body>";
}

String PageTemplate::PageFooter()
{
    return "  <footer class=\"footer\">"
           "    <p>&copy; <a href=\"https://twitter.com/herrbausm\">HerrBausM</a></p>"
           "  </footer>";
}

String PageTemplate::PageEnd()
{
    return "</body></html>";
}

String PageTemplate::NavBar()
{
    return "  <div class=\"header clearfix\">"
           "    <nav>"
           "      <ul class=\"nav nav-pills float-xs-right\">"
           "        <li class=\"nav-item\">"
           "          <a class=\"nav-link" +
           String(Title == "D1 Mini" ? " active\" href=\"#" : "\" href=\"/") +
           "\">Home</a>"
           "        </li>"
           "        <li class=\"nav-item\">"
           "          <a class=\"nav-link" +
           String(Title == "Info" ? " active\" href=\"#" : "\" href=\"/info") +
           "\">Info</a>"
           "        </li>"
           "      </ul>"
           "    </nav>"
           "    <h3 class=\"text-muted\">" +
           Title + "</h3>"
                   "  </div>";
}

