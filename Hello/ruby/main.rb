# encoding: utf-8

require 'Qt'
require './HelloWidget.rb'

app = Qt::Application.new(ARGV)
widget = HelloWidget.new
widget.show

app.exec()
