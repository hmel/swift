import os, datetime, re, time

def generateQRCTheme(dir, prefix) :
    sourceDir = os.path.abspath(dir)
    result = "<!-- WARNING: This file is automatically generated. Any changes will be overwritten. -->\n"
    result += "<RCC version =\"1.0\">"
    result += "<qresource prefix=\"/themes/" + prefix + "\">"
    for (path, dirs, files) in os.walk(sourceDir) :
        #skip the Noto emoji fonts in Windows. No need to package them since they aren't used
        dirs.sort()
        files.sort()
        for file in files :
            filePath = os.path.join(path,file)
            result += "<file alias=\"%(alias)s\">%(path)s</file>" % {
                    "alias": filePath[len(sourceDir)+1:],
                    "path": filePath
                }
    result += "</qresource>"
    result += "</RCC>"
    return result

print (generateQRCTheme(os.path.dirname("/home/face/projects/swift/Swift/resources/themes/Default"), "Default"))
