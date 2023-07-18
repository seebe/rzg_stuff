import sys
import os
import re

level = 0
file_list_names = []
file_list_indent = []
file_list_nodes_modified = []
file_list_nodes_new = []

def find_includes(file_path, directory):
    include_files = []
    with open(file_path, 'r') as f:
        for line in f:
            match = re.search(r'#include\s+"([^"]+)"', line)
            if match:
                include_file = match.group(1)
                if os.path.exists(os.path.join(directory, include_file)):
                    include_files.append(include_file)
    return include_files

def find_nodes_modified(file_path):
    nodes = []
    with open(file_path, 'r') as f:
        for line in f:
            match = re.search(r'&(\w+)\s*{', line)
            if match:
                nodes.append(match.group(1))
    return nodes

def find_nodes_new(file_path):
    nodes = []
    braces_level = 0
    with open(file_path, 'r') as f:
        for line in f:
            if line.find("{") != -1:
                braces_level = braces_level + 1
            if line.find("}") != -1:
                braces_level = braces_level - 1
            if line.find("&") != -1: # skip overide nodes
                continue
            if line.find("{") != -1:
                if braces_level == 2:
                    line = line.replace("{","") # remove braces
                    # does node have a label?
                    if line.find(":") != -1:
                        #node has label, use that
                        line = re.sub(":.*",'', line)
                    line = line.lstrip()
                    line = line.rstrip()
                    nodes.append(line)
    return nodes


def process_file(file_path, indent=0):
    directory = os.path.dirname(file_path)
    include_files = find_includes(file_path, directory)
    nodes_modified = find_nodes_modified(file_path)

    if indent == 2:
        print('└─', end='')
    if indent == 4:
        print('  └─', end='')
    if indent == 6:
        print('    └─', end='')
    if indent == 8:
        print('      └─', end='')
    print(os.path.basename(file_path))
    for include_file in include_files:
        process_file(os.path.join(directory, include_file), indent + 2)

    # Build the list in reverse order
    file_list_names.append(os.path.basename(file_path))

    # Find override nodes with &
    node_list = find_nodes_modified(file_path)
    node_list_str = ""
    count = 0
    node_list_str = node_list_str + "\n    "
    for node in node_list:
        if count == 4:
            node_list_str = node_list_str + "\n    "
            count = 0
        count = count + 1
        node_list_str = node_list_str + "&" + node
        spaces_needed = 20 - len(node)
        if (spaces_needed > 1):
            for i in range(spaces_needed):
                node_list_str = node_list_str + " "
        else:
            node_list_str = node_list_str + " "
    file_list_nodes_modified.append(node_list_str)

    # Find new nodes (no &)
    node_list = find_nodes_new(file_path)
    node_list_str = ""
    count = 0
    node_list_str = node_list_str + "\n    "
    for node in node_list:
        if count == 4:
            node_list_str = node_list_str + "\n    "
            count = 0
        count = count + 1
        node_list_str = node_list_str + node
        spaces_needed = 21 - len(node)
        if (spaces_needed > 1):
            for i in range(spaces_needed):
                node_list_str = node_list_str + " "
        else:
            node_list_str = node_list_str + " "
    file_list_nodes_new.append(node_list_str)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script_name.py <path_to_dts_file>")
        sys.exit(1)

    dts_file = sys.argv[1]
    if not os.path.isfile(dts_file) or not dts_file.endswith('.dts'):
        print("Please provide a valid .dts file path")
        sys.exit(1)

    print("-----------------------------------")
    print("Include order")
    print("-----------------------------------")
    print(" ")

    process_file(dts_file)

    print(" ")
    print(" ")
    print("-------------------------------------------------------------")
    print("Order of how files and nodes are parsed.")
    print("-------------------------------------------------------------")
    print("Remember, the #include is at the top of the files and the nodes come after. So that means the last file")
    print("that gets included will have the nodes that get processed first. This is important to know when you have")
    print("multiple files that modify the same node.")
    print(" ")


    count = len(file_list_names)
    for i in range(count):
        print(file_list_names[i] + "")

        print("  nodes new:", end='')
        print(file_list_nodes_new[i], end='')
        print(" ")
        print("  nodes override:", end='')
        print(file_list_nodes_modified[i], end='')
        print(" ")
        print(" ")

