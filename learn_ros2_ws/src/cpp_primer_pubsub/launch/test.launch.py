#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
  talker_node = Node(
    package='cpp_primer_pubsub',
    executable='talker',
    name='cpp_talker',
    output='screen'
  )

  listener_node = Node(
    package='cpp_primer_pubsub',
    executable="listener",
    name="cpp_listener",
    output='screen'
  )


  # Define LaunchDescription variable
  ld = LaunchDescription()

  ld.add_action(talker_node)
  ld.add_action(listener_node)

  return ld